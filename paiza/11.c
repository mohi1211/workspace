/********************************************
paiza count 11
********************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void){

  char str[1000];
  int i,count=0;
  fgets(str, sizeof(str), stdin);
  for(i=0;i<strlen(str);i++){
    if(str[i]=='1') count++;
  }

  if(count>=11){
    printf("OK\n");
  }else{
    printf("%d\n",count);
  }

  return 0;
}

