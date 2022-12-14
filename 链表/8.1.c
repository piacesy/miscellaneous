#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct list{
	char* s;
	struct list* next;
};
typedef struct list list;
int main(){
	char temp[60];
	list* begin=(list*)malloc(sizeof(list));
	begin->next=NULL;
	while(1){
		gets(temp);
		if(strcmp(temp,"******")==0){
			break;
		}else{
			list* new_list=(list*)malloc(sizeof(list));
			char* new_string=(char*)malloc(sizeof(char)*51);
			strcpy(new_string,temp);
			new_list->s=new_string;
			new_list->next=begin->next;
			begin->next=new_list;
		}		
	}
	list* max_len=begin->next;
	list* now=begin->next;
	FILE* fp=fopen(".\\list.txt","w");
	while(now!=NULL){
		if(strlen(now->s)>strlen(max_len->s)){
			max_len=now;
		}
		fprintf(fp,"%s\n",now->s);
		now=now->next;
	}
	printf("%s\n",max_len->s);
	return 0;
}
