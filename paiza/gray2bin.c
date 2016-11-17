/********************************************
paiza gray to bin transform

********************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void transform(int gray[400][400],int bin[400][400], int h, int w);
void makedataarray(int array[400][400],int n);
int isint(char c);

int main(void){

  char str[1000];
  int i,j;
  
  int h=0,w=0;
  int gray[400][400]={{}};
  int bin[400][400]={{}};
  
  fgets(str,sizeof(str),stdin);	
  sscanf(str,"%d %d",&h,&w);
  // printf("h = %d, w = %d\n",h,w);
  
  for(i=0;i<h;i++){
    makedataarray(gray,i);
  }
  
  transform(gray,bin,h,w);

  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      printf("%d",bin[i][j]);	
      if(j!=w-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}

void makedataarray(int array[400][400], int n){
  char str[1000] = {};
  char tmp[10]={};
  int i=0,j=0,arraynum=0;
  
  fgets(str, sizeof(str), stdin);

  while(str[i] != '\n'){
    if(isint(str[i])){
      tmp[j] = str[i];
      j++;
    }
    if(str[i+1]==' ' || str[i+1] == '\n'){
      array[n][arraynum] = atoi(tmp);
      j=0;
      arraynum++;
    }
    i++;
  }
  return;
}


int isint(char c){
  if(('0' <= c) && (c <= '9')) return 1;
  else return 0;
}

void transform(int gray[400][400],int bin[400][400],int h , int w){
  int i,j;

  for(i = 0;i < h; i++){
    for(j = 0;j < w; j++){
      if(gray[i][j]>=128){
	bin[i][j] = 1;
      }else{
	bin[i][j] = 0;
      }
    }
  }

  return;
}
      
  
  
