/********************************************
paiza make traverl with weather forecast
********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readinput(double* day, double* rp);

void readintinput(int* m, int* n);


void readinput(double* day, double* rp){
  char str[1000] ={0};
  char tmp[10] = {0};
  int i=0,j=0;

  fgets(str,sizeof(str),stdin);

  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }

  *day = atof(tmp);  
  
  i++;
  j=0;
  while((str[i] != ' ') && (str[i] != '\n') && (str[i] != EOF)){
    tmp[j] = str[i];
    i++;
    j++;
  }
  tmp[j] = '\0';
  *rp = atof(tmp);

  return;
}
void readintinput(int*m, int* n){
  char str[1000] ={0};
  char tmp[10] = {0};
  int i=0,j=0;

  fgets(str,sizeof(str),stdin);
  while((str[i] != ' ') && (str[i] != '\n')){
    tmp[j] = str[i];
    i++;
    j++;
  }

  *m = atoi(tmp);  
  
  i++;
  j=0;
  while((str[i] != ' ') && (str[i] != '\n') && (str[i] != EOF)){
    tmp[j] = str[i];
    i++;
    j++;
  }
  tmp[j] = '\0';
  *n = atoi(tmp);
  return;
}



int main(void){
  int m,n;
  int start,end;
  double avrg = 100.0;
  double tmp = 0.0;
  double items[2][32]={{0}};
  double day, rp;

  char str[1000]={0};
  int i,j;
  
  readintinput(&m,&n);


  printf("m=%d,n=%d\n",m,n);
  
  for(i=0;i<m;i++){
    readinput(&day, &rp);
    items[0][i] = day;
    items[1][i] = rp;
    printf("day =%f, rp = %f\n",day,rp);
  }

  for(i=0;i<=(m-n);i++){
    for(j=0;j<n;j++){
      tmp += items[1][i+j];
    }
    tmp = tmp / n;
    printf("%f~%f %f\n",items[0][i],items[0][i+j-1],tmp);
    if((int)avrg>(int)tmp) {
      avrg = tmp;
      start = items[0][i];
      end = items[0][i+j-1];
    }
    tmp = 0.0;
  }

  printf("%f, %d %d\n",avrg,start,end);
  return 0;
}

    
    
  
