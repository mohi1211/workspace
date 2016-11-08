/********************************************
paiza relax on treeshade
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int readinput(char * str, int* i);

int issilent(int a,int b,int r,int x,int y);

int issilent(int a, int b, int r, int x, int y){

  if(((x-a)*(x-a) + (y-b)*(y-b)) > r*r){
    return 1;
  }else{
    return 0;
  }
}

int readinput(char * str, int* i){
  char tmp[10]={0};    
  int j = 0;

  while((str[*i] != ' ')&&(str[*i] != '\n')){
    tmp[j] = str[*i];
    (*i)++;
    j++;
  }
  (*i)++;
  return atoi(tmp);
}

int main(void){

  char str[1000];
  int i= 0,j=0;
  
  int a,b,R;
  int N;
  int x[1000],y[1000];

  int judge;
  fgets(str,sizeof(str),stdin);
  
  a = readinput(str,&i);
  b = readinput(str,&i);
  R = readinput(str,&i);
  
  fgets(str,sizeof(str),stdin);
  i = 0;
  N = readinput(str,&i);

  for(j=0;j<N;j++){
    fgets(str,sizeof(str),stdin);
    i=0;
    x[j]=readinput(str,&i);
    y[j]=readinput(str,&i);
  }

  printf("%d,%d,%d,%d,%d,%d,%d,%d\n",a,b,R,N,x[0],y[0],x[1],y[1]);

  for(j = 0; j< N;j++){
    if(issilent(a,b,R,x[j],y[j])){
      printf("silent\n");
    }else{
      printf("noisy\n");
    }
  }
  return 0;
  
}

