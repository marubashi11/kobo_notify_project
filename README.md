# kobo_notify_project  

鍵を借りに行くまで工房が開いているか定かでないことが多いので、「ものつくり工房開けました」をLINEグループに自動通知するシステムを作成した。  
  
## LINE notifyの使い方  

1. オンラインサービスの「LINE notify」に自分のLineIDでログインしてLine notifyのアクセストークンを発行しておく。  
2. 送りたいLINEグループにLINE notifyを招待しておく。  
3. ubuntuターミナルで  
` curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=送りたいメッセージ' https://notify-api.line.me/api/notify `  
を実行するとメッセージをLINEグループに送ることができる。  
  
以上の手順は<https://qiita.com/takeshi_ok_desu/items/576a8226ba6584864d95>を参照した。
  
  
## 方法  

raspberry pi3内に、照明が切り替わったときだけメッセージをLINEに飛ばすプログラムを作り稼働させ続ける。 
メッセージの送信には前述のオンラインサービスLINE notifyを使用した。

## 回路  

準備中  
  
## 備考  

- プログラムのコンパイルには次のようなオプションをつける  
` g++ -std=c++0x ファイル名.cpp -lwiringPi `  
- プログラムの稼働中はraspberry piに給電し続ける必要アリ(工房から帰る前〜工房に来るまで)。 
- 光センサの読み取りに問題が多発するなら、物理的なスイッチを使うかも。
