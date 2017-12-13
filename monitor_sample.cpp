#include <iostream>
#include <cstdlib> //system関数用
#include <wiringPi.h>

constexpr int get_pin = 17;

int main(){
  if (wiringPiSetupGpio()) return 1;

  pinMode(get_pin, INPUT);
  auto last = digitalRead(get_pin); //前回値を取る

  while (true) {
    auto get = digitalRead(get_pin);
    sleep(1);

    if (get == last) continue; //値が変わっていないならループ先頭へ

    //値が切り替わったなら、その時の前回値によって分岐
    if (last == LOW) {
      std::system("curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=MONOTSUKURI workshop has been OPENED.' https://notify-api.line.me/api/notify");
    } else {
      std::system("curl -X POST -H 'Authorization: Bearer アクセストークン' -F 'message=MONOTSUKURI workshop has been CLOSED.' https://notify-api.line.me/api/notify");
    }

    last = get;
  }

  return 0;
}
