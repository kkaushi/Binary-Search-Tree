#include<stdio.h>

struct node
{
	int key;
	//char  word[20];
	//char * meaning[100];
	struct node * parent;
	struct node * left_child;
	struct node * right_child;
}* root;

