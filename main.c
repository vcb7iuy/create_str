#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "create_str.h"

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
