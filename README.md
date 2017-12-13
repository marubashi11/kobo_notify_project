# kobo_notify_project
「ものつくり工房開けました」をLINEグループに自動通知するシステムを考案中。
できる限り単純な仕組みで年内に実現予定。  
  
## LINE notifyの使い方  
1. オンラインサービスの「LINE notify」に自分のLineIDでログインしてLine notifyのアクセストークンを発行しておく。  
2. 送りたいLINEグループにLINE notifyを招待しておく。  
3. ubuntuターミナルで  
` curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=送りたいメッセージ' https://notify-api.line.me/api/notify `  
を実行するとメッセージをLINEグループに送ることができる。  
  
以上の手順は<https://qiita.com/takeshi_ok_desu/items/576a8226ba6584864d95>を参照。
  
  
## 今考えている方法  
raspberry pi3内に、光センサの値を読み取って照明が切り替わったときだけメッセージをLINEに飛ばすプログラムを作り稼働させ続ける。  
  
## 備考  
- プログラムのコンパイルには次のようなオプションをつける  
` g++ -std=c++0x ファイル名.cpp -lwiringPi `  
- プログラムの稼働中はraspberry piに給電し続ける必要アリ(工房から帰る前〜工房に来るまで)。 
- 光センサの読み取りに問題が多発するなら、物理的なスイッチを使うのもいいかも。