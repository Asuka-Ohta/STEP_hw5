#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2000000    //辞書の大きさ 200万
#define WORD_LENGTH 50  //単語の大きさ 50

int compare(const void *a, const void *b){
  return strcmp((char*)a, (char*)b );
}

int main(){
  FILE *fp,*fq;
  char data1[16]; //受け取った16文字
  char *data2; //辞書単語の文字列
  char *data3; //sortした辞書単語の文字列
  char *ch,*ch1,*ch2;
  int k=0;

  printf("please input 16 characters : \n");
  scanf("%s",data1);
  qsort(data1, sizeof(data1)-1, sizeof(data1[0]), compare);
  
  if((fp = fopen("/usr/share/dict/words", "r")) == NULL){
    printf("We can not open the file.\n");
    exit(EXIT_FAILURE);
  }
  fq  = fopen("sorted_dict.txt", "a+");
  
  //  前処理(17文字以上の単語は排除)
  while (fgets(ch, WORD_LENGTH, fp) != NULL){
    if(strlen(ch)>16){
      break;
    }
    fprintf(fq,"%s\n",ch);
  }
  
  while (fgets(ch1, WORD_LENGTH, fq) != NULL){
    int i=0,j=0;
    data2 = (char*)malloc(WORD_LENGTH);
    data3 = (char*)malloc(WORD_LENGTH);
    fgets(data2, WORD_LENGTH, fq);
    strcpy(data3,data2);
    qsort(data3, sizeof(data3)-1, sizeof(data3[0]), compare);    
    while(i<16){
      if(data1[i]==data3[j]){
	i++;
	j++;
      }else
	i++;
    }
    if(i<16){
      if(k < strlen(data2)){
	k = strlen(data2);
	ch2 = data2;
      }
    }
    free(data2);
    free(data3);
  }
  
  printf("The longest word : %s\n",ch2);
  fclose(fp);
  fclose(fq);
  return 0;
}
