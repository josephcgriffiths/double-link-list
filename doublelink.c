#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *prev;
	struct node *next;
} nt;

void print_list(nt *head){
	nt *current = head;
	while(current!=NULL){
		printf("%d\n", current->val);
		current = current->next;
	}
}

void print_list_back(nt *head){
	nt *current = head;

	while(current->next!=NULL){
		current = current->next;
	}

	while(current!=NULL){
		printf("%d\n", current->val);
		current = current->prev;
	}
}

void push(nt *head, int val){
	nt *current = head;
	while(current->next!=NULL){
		current=current->next;
	}

	current->next = malloc(sizeof(nt));
	current->next->val = val;
	current->next->prev = current;
	current->next->next = NULL;
}

int main(){
	nt *head = NULL;

	head = malloc(sizeof(nt));
	head->val = 1;
	head->prev = NULL;
	head->next = NULL;

	push(head, 2);
	push(head, 3);

	print_list_back(head);
}
