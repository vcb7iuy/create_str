#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFERSIZE 20
#define ON 1
#define OFF 0
#define OPTION 5

enum {
  ALL,
  NUM,
  UP,
  LOW,
  SYM,  
};

void create_str( const char* const );  // 文字列を生成する関数

const char number[] = "0123456789";
const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lower[] = "abcdefghijklmnopqrstuvwxyz";
const char symbol[] = " !\"#$%&'()*+,-./:;<=>\?@[\\]^_`{|}~";

int main( int argc, char** argv ) {
  int flag[OPTION];

  flag[ALL] = OFF;
  flag[NUM] = OFF;
  flag[UP] = OFF;
  flag[LOW] = OFF;
  flag[SYM] = OFF;

  /* 引数の確認 */
  if ( argc < 2 ) {
    printf("Usege: <プログラム名> <オプション値>\n");
    printf("オプション値:\n");
    printf("-a: all\n");
    printf("-n: number\n");
    printf("-u: upper char\n");
    printf("-l: lower char\n");
    printf("-s: symbol\n");
    exit(1);
  }

  /* 引数の処理 */
  int opt;
  while ( ( opt = getopt( argc, argv, "anuls" ) ) != -1 ) {
    switch( opt ) {
    case 'a':
      flag[ALL] = ON;
      break;
    case 'n':
      flag[NUM] = ON;
      break;
    case 'u':
      flag[UP] = ON;
      break;
    case 'l':
      flag[LOW] = ON;
      break;
    case 's':
      flag[SYM] = ON;
      break;
    default:
      ;
    }
  }

  /* 文字列生成に使う文字の設定 */
  char use_str[ sizeof(number) + sizeof(upper)
                + sizeof(lower) + sizeof(symbol) + 1 ];   // 文字列生成に使う文字
  memset( use_str, '\0', sizeof(use_str) );

  if ( flag[ALL] ) {
    strcat( use_str, number );
    strcat( use_str, upper );
    strcat( use_str, lower );
    strcat( use_str, symbol );
  }
  else {
    if ( flag[NUM] ) {
      strcat( use_str, number );
    }
    
    if ( flag[UP] ) {
      strcat( use_str, upper );
    }
    
    if ( flag[LOW] ) {
      strcat( use_str, lower );
    }
    
    if ( flag[SYM] ) {
      strcat( use_str, symbol );
    }
  }

  if ( use_str[0] ) {
    create_str( use_str );    // 文字列を生成
  }
    
  return 0;
}


/* 文字列を生成する関数 */
void create_str( const char* const use_str ) {
  char str[BUFFERSIZE + 1];                 // 生成文字列  +1: '\0'用
  memset( str, '\0', sizeof(str) );
  
  const char* tmp_str[BUFFERSIZE + 1];      // 文字へのポインタ
  memset( tmp_str, (int)NULL, sizeof(tmp_str) );
  
  /* 文字列を生成 */
  int i = 0;
  int j = 0;
  int length = 1;
  while ( length <= BUFFERSIZE ) {
    tmp_str[0] = use_str + i;

    for ( j = 0; j < length && length <= BUFFERSIZE; j++ ) { 
      if ( !(*tmp_str[j]) ) {           // '\0'の場合、繰り上げ処理を実行
        tmp_str[j] = use_str;
        i = 0;

        if ( !tmp_str[j+1] ) {          // NULLの場合、繰り上げ先を初期化
          tmp_str[j+1] = use_str;       
          length++;
        }
        else {
          tmp_str[j+1]++;
        }
      }
      
      str[j] = *tmp_str[j];
    }

    i++;
    printf("%s\n", str);
  }
  
  return ;
}

