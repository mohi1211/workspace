/********************************************
paiza piraimd
********************************************/

#include <stdlib.h>
#include <stdio.h>
int main(void){
  // 自分の得意な言語で
  // Let's チャレンジ
  char str[1000];
  int num,sum,i;
  fgets(str, sizeof(str), stdin);
  num = atoi(str);
  sum = 0;
  for(i = 1; i <= num; i++){
    sum += i;
  }
  printf("%d\n", sum);
  return 0;
}
