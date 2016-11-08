/********************************************
paiza Winter or Summer Fashion
********************************************/



#include <stdio.h>
int main(void){
  // 自分の得意な言語で
  // Let's チャレンジ
  char str[1000];
  int iswinter = 0;
  /*
    iswinter > 0 => winter
    iswinter< 0 => summer
    iswinter == 0 => else
   */
  int i;
  fgets(str, sizeof(str), stdin);
  for(i=0;i<10;i++){
    if(str[i] =='W'){
      iswinter++;
    }else if(str[i] == 'S'){
      iswinter--;
    }
  }
  if(iswinter>0){
    printf("OK\n");
  }else{
    printf("NG\n");
  }
  return 0;
}
