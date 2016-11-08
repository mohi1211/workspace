#include<stdio.h>
#include<string.h>

void leet_replace(char* c);

void leet_replace(char* c){

  switch(*c){
  case 'A':
    *c = '4';
    break;
  case 'E':
    *c = '3';
    break;
  case 'G':
    *c = '6';
    break;
  case 'I':
    *c = '1';
    break;
  case 'O':
    *c = '0';
    break;
  case 'S':
    *c = '5';
    break;
  case 'Z':
    *c = '2';
    break;
  }
  return;
}

int main(void){

  char str[1000];
  int i;
  fgets(str,sizeof(str),stdin);

  for(i=0;i<strlen(str);i++){
    leet_replace(&str[i]);
  }
  printf("%s",str);

  return 0;
}
