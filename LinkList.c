#include <stdio.h>

typedef struct node{
    int data;
	struct node *next;
}NODE,*LinkList;

LinkList Find_List(LinkList L,int k){
  LinkList p;
  int i;
  i = 1;
  p = L->next;
  while(p&&i<k){
	p = p->next;
	i++;  
  }
	
  if(p&&i==k) return p;
  return NULL;	
} /* Find_List */

int Insert_List(LinkList L,int k,int newElem){
  LinkList p,s;
  if(k==1) p = L;
  else p = Find_List(L,k-1);
  
  if(!p) return -1;
  s = (NODE *)malloc(sizeof(NODE));
  if(!s) return -1;
  s->data = newElem;
  s->next = p->next;
  p->next = s;
  return 0;
} /* Insert_List */

void Show_List(LinkList L,int k){
  	LinkList p = L->next;
	
	while(k>0){
	  	printf( "%d ", p->data);
		p = p->next;
		k--;
	}
} /* Show_List */

int main()
{
    LinkList linkList;
	Insert_List(linkList,1,1);
	Insert_List(linkList,1,2);
	Insert_List(linkList,1,3);
	Insert_List(linkList,2,5);
	
	Show_List(linkList,4);
	
    return 0;
}
