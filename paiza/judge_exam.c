#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void extract(char* t,int* e, int * m,int* s, int* J, int*g);

void extract(char* t,int* e, int * m,int* s, int* J, int*g){
  char str[1000]={0};
  int i=0,j=0;
  char tmp[10]={0};
  fgets(str,sizeof(str),stdin);
  //  printf("%s\n",str);
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }
  *t = tmp[j-1];
  //  printf("t=%c\n", *t);
  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
    tmp[j] = '\0';
  }
  *e = atoi(tmp);
  //  printf("e = %d\n",*e);
  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
    tmp[j] = '\0';
  }
  *m = atoi(tmp);
  //  printf("m = %d\n",*m);
  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
    tmp[j] = '\0';
  }
  *s = atoi(tmp);
  //  printf("s = %d\n",*s);
  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
    tmp[j] = '\0';
  }
  *J = atoi(tmp);
  //  printf("J = %d\n",*J);
  j=0;
  i++;
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
    tmp[j] = '\0';
  }
  *g = atoi(tmp);
  //  printf("g = %d\n",*g);
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
    printf("sum = %d\n",sum);
    if(t=='s'){
      s_sum = m + s;
          printf("s_sum = %d\n",s_sum);
      if( (sum>=350) && (s_sum>=160)) count++;
      
    }else{
      l_sum = j + g;
          printf("l_sum = %d\n",l_sum);
      if( (sum>=350) && (l_sum>=160)) count++;
    }
  }
  printf("%d\n",count);
  return 0;
}

    

    
