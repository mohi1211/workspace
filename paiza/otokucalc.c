/********************************************
paiza otokucalc.c
********************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FOOD 0
#define BOOK 1
#define CLOTH 2
#define OTHER 3


void readinput(int* kind, int* price);

void readinput(int* kind, int* price){
  char str[1000]={0};
  char tmp[10]={0};
  int i;
  
  fgets(str,sizeof(str),stdin);
  *kind = (int)(str[0]) - (int)('0');
  i=2;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[i-2] = str[i];
    i++;
  }
  *price = atoi(tmp);

  return;
}


int main(void){

  int item[2][1024]={{0}};
  int food_sum=0,book_sum=0,cloth_sum=0,other_sum=0,p_sum=0;
  int N;
  
  char str[1000]={0};
  int i,kind,price;

  fgets(str,sizeof(str),stdin);
  N = atoi(str);

  for(i=0;i<N;i++){
    readinput(&kind,&price);
    item[0][i] = kind;
    item[1][i] = price;
    if(kind==FOOD) food_sum += price;
    else if(kind == BOOK) book_sum += price;
    else if(kind == CLOTH) cloth_sum += price;
    else if(kind == OTHER) other_sum += price;
    //    printf("kind = %d, price = %d, fsum = %d, bsum = %d, csum = %d,osum = %d\n",kind,price,food_sum,book_sum,cloth_sum,other_sum);
  }


  p_sum =p_sum + (food_sum/100) * 5;
  p_sum =p_sum + (book_sum/100) * 3;
  p_sum += (cloth_sum/100) * 2;
  p_sum += (other_sum/100) * 1;
  
  printf("%d\n",p_sum);
  
  return 0;
}
