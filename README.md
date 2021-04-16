# mycp2

直接システムコールを使用してファイルコピープログラムを作る．

1. 演習の手順．

  - 前回と同様
  - 授業で説明した注意点は再確認

2. 作るもの(`mycp2`プログラム)

  - ３年次に作成した`mycp`と同じように動作するファイルコピープログラム
  - 但し，`open`，`read`，`write`，`close`システムコールを使用する．
  - バッファサイズより大きなファイルのコピーもできること．
  - ファイルサイズがバッファサイズの整数倍とは限らない．
  - コマンド行引数のチェックは必須．
  - `open` システムコールエラーチェックも必須．
  - システムコールのエラーメッセージは`perror()`関数で表示する．

3. 動作テストの例<br>
  ランダムなデータを含む大きさ10KiBのファイルを作り， `mycp2`プログラムを使ってコピーする．<br>
  最後にコピーしたファイルの内容が元の10KiBのファイルと同じことを確認する．

  ```
  $ dd if=/dev/urandom of=srcfile bs=1024 count=10 # ランダムな内容の
  10+0 records in                                  # 10KiBのファイルを作成する
  10+0 records out 10240 bytes transferred in 0.001528 secs (6701462 bytes/sec)
  $ ./mycp2 srcfile destfile                       # mycp2 プログラムを実行する
  $ cmp srcfile destfile                           # コピー元とコピー先ファイルを比較する
  $                                                # 内容が同じなら何も表示されない
  ```
