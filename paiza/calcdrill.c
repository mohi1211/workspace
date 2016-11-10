/********************************************
paiza calcdrill
********************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define op_NUM


int main(void){

  char str[1000];
  int i=0;
  int a=0,b=0,c=0;
  int x_a,x_b,x_c;
  char op;
  char whereisx;

  fgets(str,sizeof(str),stdin);
  if(str[0]!='x'){
    a = (int)(str[0])-(int)('0');
  }else{
    whereisx = 'a';
  }

  op = str[2];

  if(str[4]!='x'){
    b = (int)(str[4])-(int)('0');
  }else{
    whereisx = 'b';
  }

  if(str[8]!='x'){
    c = (int)(str[8])-(int)('0');
  }else{
    whereisx = 'c';
  }

  x_b = c-a;
  if(op=='-'){
    b = (-1) * b;
    x_b = (-1) * x_b;
  }
  x_a = c - b;
  x_c = a + b;

  printf("a = %d, b = %d, c = %d, whereisx = %c\n",a,b,c,whereisx);
  printf("x_a = %d, x_b = %d, x_c = %d\n",x_a,x_b,x_c);

  switch(whereisx){
  case'a':
    printf("%d\n",x_a);
    break;
  case'b':
    printf("%d\n",x_b);
    break;
  case'c':
    printf("%d\n",x_c);
    break;
  }

  return 0;
}
      
  
  
    
  
