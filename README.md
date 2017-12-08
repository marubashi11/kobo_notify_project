# kobo_notify_project
「ものつくり工房開けました」をLINEグループに自動通知するシステムを考案中。
できる限り単純な仕組みかつ安価で年内に実現予定。

##LINE notifyの使い方
1.オンラインサービスの「LINE notify」に自分のLineIDでログインしてLine notifyのアクセストークンを発行しておく。
2.送りたいLINEグループにLINE notifyを招待しておく。
3.ubuntuターミナルで
`curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=送りたいメッセージ' https://notify-api.line.me/api/notify`
を実行するとメッセージをLINEグループに送ることができる。

以上の手順は<https://qiita.com/takeshi_ok_desu/items/576a8226ba6584864d95>を参照。

##現在やろうとしていること
raspberry pi3内に次のようなシェルスクリプトを作る。
`
\#!/bin/sh

sleep(10)

curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=MONOTSUKURI studio has been opened.' https://notify-api.line.me

sudo shutdown -h now
`
このシェルスクリプトを/etc/profile.d/に置いておくと、raspberry pi3起動時に自動で実行される(テスト済)。
あとは「工房内に鍵が置かれたとき」や「電灯がついたとき」などの条件でraspberry piに給電されるような仕組みを作ればうまくいくはず。

##問題点
*給電する仕組みを具体的にどうするか考えていない。できるだけボタンスイッチなどの意図的な動作が必要な仕組みは避けたい。
*やることとコストが見合ってない。もっと安価なもの(ESP32-DerKitCなど)で実現するか、raspberry piを使う価値があるだけの機能を追加したい。
