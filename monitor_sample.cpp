#include <iostream>
#include <cstdlib> //system�ؿ���
#include <wiringPi.h>

constexpr int get_pin = 17;

int main(){
  if (wiringPiSetupGpio()) return 1;

  pinMode(get_pin, INPUT);
  auto last = digitalRead(get_pin); //�����ͤ���

  while (true) {
    auto get = digitalRead(get_pin);
    sleep(1);

    if (get == last) continue; //�ͤ��Ѥ�äƤ��ʤ��ʤ�롼����Ƭ��

    //�ͤ��ڤ��ؤ�ä��ʤ顢���λ��������ͤˤ�ä�ʬ��
    if (last == LOW) {
      std::system("curl -X POST -H 'Authorization: Bearer ���������ȡ�����' -F 'message=MONOTSUKURI workshop has been OPENED.' https://notify-api.line.me/api/notify");
    } else {
      std::system("curl -X POST -H 'Authorization: Bearer ���������ȡ�����' -F 'message=MONOTSUKURI workshop has been CLOSED.' https://notify-api.line.me/api/notify");
    }

    last = get;
  }

  return 0;
}
