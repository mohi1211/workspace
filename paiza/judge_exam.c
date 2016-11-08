#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void extract(char* t,int* e, int * m,int* s, int* J, int*g);

void extract(char* t,int* e, int * m,int* s, int* J, int*g){
  char str[1000]={0};
  int i=0,j=0;
  char tmp[10]={0};
  fgets(str,sizeof(str),stdin);
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }
  *t = tmp[j];
  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }
  *e = atoi(tmp);
  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }
  *m = atoi(tmp);

  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }
  *s = atoi(tmp);

  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }
  *J = atoi(tmp);

  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }
  *g = atoi(tmp);

  j=0;
  i++;

  return;
}


int main(void){

  char str[1000];
  int i;
 
  char t;
  int e,m,s,j,g;
  int N;
  int sum = 0, l_sum = 0, s_sum = 0;
  int count = 0;

  fgets(str,sizeof(str), stdin);

  N = atoi(str);


  for(i=0;i<N;i++){
    extract(&t, &e,&m,&s,&j,&g);
    sum = e + m + s + j + g;
    if(t=='s'){
      s_sum = m + s;
      if( (sum>=350) && (s_sum>=160)) count++;
    }else{
      l_sum = j + g;
      if( (sum>=350) && (l_sum>=160)) count++;
    }
  }
  printf("%d\n",count);
  return 0;
}

    

    
