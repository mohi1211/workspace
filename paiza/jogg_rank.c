/********************************************
paiza output this_month_ranking

********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct member{
  char name[100];
  char updown[10];
  int last_rank;
  int rank;
  int score;
  /*
    score means distans who ran
   */
};

struct rank_list{
  struct member *ptr;
  struct rank_list *next;
  struct rank_list *previous;
};


void read_last_rank(struct member *array, int n);
void read_new_score(struct member * array);
void print_new_rank(struct member *array);
void make_rank(struct member *m, struct rank_list **start, struct rank_list *rank);

int main(int argc, char* argv[]){
  char str[1000];
  int i;
  
  int n,m,t;
  struct member *array;
  struct rank_list *start=NULL,*current_r;
  struct rank_list rank[100]={};

    fgets(str,sizeof(str),stdin);

  sscanf(str,"%d %d %d",&n,&m,&t);

  array = (struct member*)malloc(sizeof(struct member) * n);
  if(array == NULL){
    printf("memory allocation error\n");
    exit(EXIT_FAILURE);
  }

  
  for(i=0;i<n;i++){
    read_last_rank(array, i);
  }
  
  
  for(i=0;i<m;i++){
    read_new_score(array);
  }


  start = &rank[0];
  rank[0].ptr=&array[0];
  rank[0].next=NULL;
  rank[0].previous=NULL;
  
  for(i = 1;i<n;i++){
    make_rank(&array[i],&start,&rank[i]);
  }
  
  current_r = start;
  for(i=0;i<n;i++){
    current_r->ptr->rank=i;
    
    if(current_r->ptr->rank > current_r->ptr->last_rank)
      strcpy(current_r->ptr->updown,"up");
    else if(current_r->ptr->rank == current_r->ptr->last_rank)
      strcpy(current_r->ptr->updown,"same");
    else if(current_r->ptr->rank < current_r->ptr->last_rank)
      strcpy(current_r->ptr->updown,"down");
    current_r = current_r->next;
  }
           
  current_r=start;
  for(i=0;i<t;i++){
    printf("%s %d %s\n",
           current_r->ptr->name,current_r->ptr->score,current_r->ptr->updown);
    if(current_r->next!=NULL) current_r = current_r->next;
  }

  free(array);
  return 0;
}

void read_last_rank(struct member *array,int n){
  char str[1000]={};
  char tmp_name[100]={};
  int tmp_score;
    

  fgets(str,sizeof(str),stdin);
  sscanf(str,"%s %d",tmp_name,&tmp_score);

  strcpy(array[n].name,tmp_name);
  
  array[n].last_rank = n;
  array[n].score = 0;
  return;
}

void read_new_score(struct member * array){
  char str[1000] = {};
  char tmp_name[100]={};
  int tmp_day,tmp_score;
  int i=0;
  fgets(str,sizeof(str),stdin);
  sscanf(str,"%d %s %d",&tmp_day,tmp_name,&tmp_score);

  while(strcmp(array[i].name,tmp_name)!=0){
    i++;
  }
  array[i].score += tmp_score;

  return;
}

void make_rank(struct member *m, struct rank_list **start, struct rank_list *rank){

  struct rank_list *current_r;
  
  rank->ptr=m;
  rank->next = NULL;
  rank->previous = NULL;
  /*
  if(start == NULL){
    start = rank;
    printf("--initialize start\n");
    printf("--start is %p\n",start);
    printf("--score is %d name is %s\n",start->ptr->score,start->ptr->name);
    
    return;
  }
  */
  current_r = *start;
  do{
    if(current_r->ptr->score > m->score){
      if(current_r->next != NULL){
        current_r = current_r->next;
      }
      else{
        current_r->next=rank;
        rank->previous=current_r;
        return;
      }
      
    }else{
      if(current_r->previous==NULL){
        *start = rank;
        rank->previous=NULL;
      }else{
        current_r->previous->next = rank;
        rank->previous=current_r->previous;       
      }        
      current_r->previous = rank;
      rank->next=current_r;
      return;
    }
    /*
  }while(current_r->next != NULL);
    */
  }while(1);
  return;
  
}
