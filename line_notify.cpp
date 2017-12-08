#include <iostream>
#include <stdlib.h>

int main(){
  system("curl -X POST -H 'Authorization: Bearer EkMV5gu0rDPRxW8Ka84eqEUqUfQ1znCr79FicvYCLlX' -F 'message=MONOTSUKURI studio has been opened.' -F 'imageThumbnail=http://go-koike.com/wp-content/uploads/2016/05/slproImg_201605311040270.jpg' -F 'imageFullsize=http://go-koike.com/wp-content/uploads/2016/05/slproImg_201605311040270.jpg' https://notify-api.line.me/api/notify");
  
  return 0;
}
