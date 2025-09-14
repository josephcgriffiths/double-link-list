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

int delete_item(nt **head, int n){
	if(!head||!*head||n<0) return -1;

	int i = 0;
	int retval = -1;
	nt *current = *head;

	while(current && n > i){
		current = current->next;
		i++;
	}

	if(current->prev){
		current->prev->next = current->next;
	} else {
		*head = current->next;
	}

	if(current->next){
		current->next->prev = current->prev;
	}

	free(current);
	return retval;
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
	delete_item(&head, 2);

	print_list(head);
}
