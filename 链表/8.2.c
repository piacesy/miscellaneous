#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct list{
	struct list* next;
	char* s;
};
typedef struct list list;
void print_menu();
void print_list(list* begin);
void add(list* begin,int *len,char* s,int i);
void delete(list* begin,char* s,int *len);
void search(list* begin,char* s);
void update(list* begin,char* s,int pos,int* len);
void swap(list* begin,list*pre);
void out_put(list* begin);
int main(){
	char op;
	int len=0;
	int flag=1;
	list* begin=(list*)malloc(sizeof(list));
	begin->next=NULL;
	while(flag){
		print_menu();
		op=getchar();
		switch(op){
			case '1':{
				printf("��������Ҫ��ӵ�����:\n");
				int i;
				char* temp=(char*)malloc(sizeof(char)*30);
				scanf("%d%s",&i,temp);
				add(begin,&len,temp,i);
				print_list(begin);
				break;
			}
			case '2':{
				char* temp=(char*)malloc(sizeof(char)*30);
				printf("��������Ҫɾ��������:\n");
				scanf("%s",temp);
				delete(begin,temp,&len);
				free(temp);
				print_list(begin);
				break;
			}
			case '3':{
				char* temp=(char*)malloc(sizeof(char)*30);
				printf("��������Ҫ���ҵ�����:\n");
				scanf("%s",temp);
				search(begin,temp);
				free(temp);
				break;
			}
			case '4':{
				int i;
				char* temp=(char*)malloc(sizeof(char)*30);
				printf("��������Ҫ���µ�����:\n");
				scanf("%d%s",&i,temp);
				update(begin,temp,i,&len);
				print_list(begin);
				break;
			}
			case '5':{
				swap(begin->next,begin);
				print_list(begin);
				break;
			}
			case '0':{
				flag=0;
				out_put(begin);
				break;
			}
				
		}
	}
}
void print_menu(){
	printf("1.��������\n2.ɾ������\n3.��������\n");
	printf("4.��������\n5.�������\n0.�˳�\n");
	printf("����������ѡ��:\n");
}
void print_list(list* begin){
	printf("Ŀǰ������Ϊ��");
	if(begin->next==NULL){
		printf("��\n");
		return;
	}
	begin=begin->next;
	while(begin!=NULL){
		if(begin->next!=NULL){
			printf("%s->",begin->s);
		}else{
			printf("%s\n",begin->s);
		}
		begin=begin->next;
	}
}
void add(list *begin,int* len,char* s,int i){
	if(i>*len){
		while(begin->next!=NULL){
			begin=begin->next;
		}
		list* new_list=malloc(sizeof(list));
		new_list->next=NULL;
		new_list->s=s;
		begin->next=new_list;
	}else{
		for(int j=0;j<i;j++){
			begin=begin->next;
		}
		list* new_list=malloc(sizeof(list));
		new_list->next=begin->next;
		new_list->s=s;
		begin->next=new_list;
	}
	(*len)++;
}
void delete(list* begin,char* s,int *len){
	int flag=0;
	list* pre=begin;
	begin=begin->next;
	while(begin!=NULL){
		if(strcmp(begin->s,s)==0){
			flag=1;
			pre->next=begin->next;
			break;
		}
		pre=begin;
		begin=begin->next;
	}
	if(flag==0){
		printf("���ַ���������������\n");
	}else{
		(*len)--;
	}
}
void search(list* begin,char* s){
	begin=begin->next;
	int flag=0;
	int pos=0;
	while(begin!=NULL){
		if(strcmp(begin->s,s)==0){
			flag=1;
			printf("�ýڵ��ٵ�%d��λ��\n",pos);
			break;
		}
		begin=begin->next;
		pos++;
	}
	if(flag==0){
		printf("�ý�㲻��������\n");
	}
}
void update(list* begin ,char* s,int pos,int* len){
	if(pos>=*len){
		add(begin,len,s,pos);
	}else{
		begin=begin->next;
		for(int i=0;i<pos;i++){
			begin=begin->next;
		}
		free(begin->s);
		begin->s=s;
	}
}
void swap(list* begin,list* pre){
	if(begin==NULL||begin->next==NULL){
		return;
	}else{
		list* pos=begin->next;
		pre->next=pos;
		begin->next=pos->next;
		pos->next=begin;
		swap(begin->next,begin);
	}
}
void out_put(list* begin){
	begin=begin->next;
	FILE* fp=fopen(".\\Output.txt","w");
	while(begin!=NULL){
		if(begin->next==NULL){
			fprintf(fp,"%s\n",begin->s);
		}else{
			fprintf(fp,"%s->",begin->s);
		}
		begin=begin->next;
	}
}
