#include <stdio.h>
#include <string.h>

int main(void){
  // 自分の得意な言語で
  // Let's チャレンジ
  char str[1000];
  char choco[20] = "chocolate";
  char candy[20] = "candy";
  int i;
  fgets(str, sizeof(str), stdin);
  for(i=0;i<strlen(str);i++){
    str[i]=tolower(str[i]);
    if(str[i] == '\n') str[i] = '\0';
  }
  
  printf("str = %s  choco = %s, candy = %s\n",str,choco,candy);
  if((strcmp(str,choco)==0) || (strcmp(str,candy)==0)){ 
    printf("Thanks!\n");
  }else{
    printf("No!\n");
  }
  return 0;
}
