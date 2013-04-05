#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "create_str_p.h"

/* 文字列を生成する関数 */
void create_str( const char* const use_str ) {
  char* str;                                 // 生成文字列
  str = (char *)malloc( BUFFERSIZE + 1 );    // +1: '\0'用

  if ( !str ) {
    perror("error: str");
    exit(1);
  }
  
  memset( str, '\0', sizeof(str) );
  
  const char** tmp_str;                      // 文字へのポインタ
  tmp_str = (const char **)malloc( BUFFERSIZE + 1 );

  if ( !tmp_str ) {
    perror("error: tmp_str");
    free(str);
    exit(1);
  }
  
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

  free(str);
  free(tmp_str);
  
  return ;
}
