#include <stdio.h>                 // perror のため
#include <stdlib.h>                // exit のため
#include <fcntl.h>                 // open のため
#include <unistd.h>                // read,write,close のため
#define  BSIZ 1000                 // バッファサイズ

int main(int argc, char *argv[]) {
  int fd1;                         // コピー元用のFD(ファイルディレクトリ)
  int fd2;                         // コピー先用のFD(ファイルディレクトリ)
  ssize_t len;                     // 実際に読んだバイト数
  char buf[BSIZ];                  // バッファ
  
  //openシステムコール

  fd1 = open("argv[1], O_RDONLY);        //コピー元用のFDを読み出し用にオープン
  fd2 = open("argv[2], O_WRONLY, 0644);  //コピー先用のFDを書き出し用にオープン
             
  if(fd1<0){                       //openシステムコールのエラーチェック
    perror("argv[1]");　　　　　　　//argv[1]にエラー原因を表示
    exit(1);                       //エラー表示
  }
  
  if(fd2<0){                       //openシステムコールのエラーチェック
    perror("argv[2]");             //argv[2]にエラー原因を表示
    exit(1);                       //エラー表示
  }
  
  //readシステムコール
             
  int n=0;                         //int型の変数nを宣言し0を代入する
  while ((n = read(fd1, buf, 100)) > 0){  
       //readシステムコールでファイルの先頭から順番にデータを読み出す
    ssize_t len = ssize_t len + n;         //現在時点のバイト数を表示
  }
             
  if(fd1<0){                       //readシステムコールのエラーチェック
    perror("argv[1]");　　　　　　　//argv[1]にエラー原因を表示
    exit(1);                       //エラー表示
  }
             
  //writeシステムコール
             
  while ((n = write(fd2, buf, ssize_t len)) > 0){
       //writeシステムコールでファイルの先頭から順番にデータを書き込む
  }
  
  if(fd2<0){                       //writeシステムコールのエラーチェック
    perror("argv[2]");             //argv[2]にエラー原因を表示
    exit(1);                       //エラー表示
  }
  
  close(fd1);
  close(fd2);
  return 0;                        // 正常終了
}
