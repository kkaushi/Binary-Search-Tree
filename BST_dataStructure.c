#include<stdio.h>
#include"BST_node.c"


//====Modules for insertion in BST ================================================================//

struct node *create_new_node(int data)
{
	struct node * ptr;
	ptr=malloc(sizeof(struct node));
	ptr->key=data;
	ptr->left_child=NULL;
	ptr->right_child=NULL;
	ptr->parent=NULL;
	//puts("Enter the word");
	//gets(ptr->word);
	//puts("Enter the meaning");
	//gets(ptr->meaning);
	return ptr;

}

void insert_node_at_position(struct node **ptr,int data,struct node * parent_ptr)
{
	struct node * temp;
	temp=create_new_node(data);
	*ptr=temp;
	((struct node *)(*ptr))->parent=parent_ptr;
}

void find_position_to_insert(struct node * temp,int data)
{
	
	if(data<temp->key)
	{
		if(temp->left_child!=NULL)
			find_position_to_insert(temp->left_child,data);
		else 
			insert_node_at_position(&temp->left_child,data,temp);
			//return temp->left_child;

	}
	else
	{
		if(temp->right_child!=NULL)
			find_position_to_insert(temp->right_child,data);	
		else
			insert_node_at_position(&temp->right_child,data,temp);
			//return temp->right_child;
	}

	/*if(data<temp->key && temp->left_child!=NULL)
		find_position_to_insert(temp->left_child,data);
	else return temp->left_child;

	if(data>temp->key && temp->right_child!=NULL)
		find_position_to_insert(temp->right_child,data);
	else return temp->right_child;*/
}

void insert_node(int data)
{
	
	if(root==NULL)
	{
		//root=malloc(sizeof(struct node));
		insert_node_at_position(&root,data,NULL);
	}
	else 
	{
		//struct node*temp,*ptr;	
		//temp=root;
		find_position_to_insert(root,data);
		//ptr=find_position_to_insert(temp,data);
		//insert_node_at_position(&ptr,data);
	}

}



//====Modules for insertion in BST ================================================================//



//====Modules for traversal in BST ================================================================//
/*void preorder_traversal(int val)
{
	struct node * ptr=root;
	while(ptr->key!=val && ptr!=NULL)
	{
		if(val<ptr->key)

	}
}*/
void preorder(struct node * ptr)
{
	if(ptr!=NULL)
	{	
		//printf("%d\t%s\t%s\n",ptr->key,ptr->word,ptr->meaning);
		printf("%d\n",ptr->key);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	
	}
	else
		return;
}



void inorder(struct node * ptr)
{
	if(ptr!=NULL)
	{	
		
		inorder(ptr->left_child);
		//prntf("%d\t%s\t%s\n",ptr->key,ptr->word,ptr->meaning);
		printf("%d\n",ptr->key);
		//puts(ptr->word);
		//puts(ptr->meaning);
		inorder(ptr->right_child);
	
	}
	else
		return;
}


void postorder(struct node * ptr)
{
	if(ptr!=NULL)
	{	
		
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%d\n",ptr->key);
		//printf("%d\t%s\t%s\n",ptr->key,ptr->word,ptr->meaning);
	
	}
	else
		return;
}



//====Modules for traversal in BST ================================================================//











//====Modules for MAX/MIN in BST ================================================================//
struct node * max_in_bst(struct node * ptr)
{
	if(ptr->right_child!=NULL)	
		max_in_bst(ptr->right_child);
	else
		//printf("%d\n",ptr->key);
		return ptr;
	return;
	
}

struct node * min_in_bst(struct node * ptr)
{
	if(ptr->left_child!=NULL)	
		min_in_bst(ptr->left_child);
	else
	{
		printf("%d\n",ptr->key);
		return ptr;
	}
		
}

//====Modules for MAX/MIN in BST ================================================================//












//====Modules for Successor/predecessor in BST ================================================================//

//to understand this method see page 259 of coreman pdf
struct node * successor(struct node * ptr)
{
	struct node * temp;
	if(ptr->right_child!=NULL)
	{
		temp=min_in_bst(ptr->right_child);
		return temp;
	}
	else 
	{
		
		int data=ptr->key;
		if(ptr->parent!=NULL)
			temp=ptr->parent;
		else 
			return NULL;
		if(temp->right_child!=NULL)
			while(temp!=NULL && data==temp->right_child->key)
			{
				data=temp->key;
				temp=temp->parent;
				if(temp==NULL || temp->right_child==NULL)
					break;
			}
		if(temp==NULL)
		{
			//printf("no successor\n");
			return NULL;
		}
		else if(data==temp->left_child->key)
		{
			printf("successor is:%d\n",temp->key);
			return temp;
		}


	}
}


struct node * predecessor(struct node * ptr)
{
	struct node * temp;
	if(ptr->left_child!=NULL)
	{	
		temp=max_in_bst(ptr->left_child);
		return temp;
	}
	else 
	{
		struct node * temp;
		int data=ptr->key;
		if(ptr->parent!=NULL)
			temp=ptr->parent;
		else
			return NULL;
		if(temp->left_child!=NULL)
 			while(temp!=NULL && data==temp->left_child->key)
			{
				data=temp->key;
				temp=temp->parent;
				if(temp==NULL || temp->left_child==NULL)
					break;
			
			}
		if(temp==NULL)
			//printf("successor is:%d\n",data);
			//printf("no predecessor\n");
			return NULL;
		else if(data==temp->right_child->key)
			//printf("predecessor is:%d\n",temp->key);
			return(temp);


	}
}




//====Modules for Successor/predecessor in BST ================================================================//












//====Modules for Node Search in BST ================================================================//

void search_node(struct node * ptr,int val)
{
		
	
	if(ptr==NULL)
		puts("node doesnot exists");
	else if(ptr->key==val)
		puts("node exists");
	else if(val<ptr->key)
		search_node(ptr->left_child,val);
	else if(val>ptr->key)
		search_node(ptr->right_child,val);
		
}	

void search(int val)
{
	search_node(root,val);
}


//====Modules for Node Search in BST ================================================================//






//====Modules for Node Delete in BST ================================================================//

void spliceOut(struct node * ptr,struct node * child)
{
	if(ptr==root)
	{
		root=NULL;
		root=child;
	}
	else
	{
		child->parent=ptr->parent;
		if(ptr==ptr->parent->right_child)
			child->parent->right_child=child;
		else
			child->parent->left_child=child;
		

	}
	//free(ptr);
	
}


void replace_node(struct node * ptr,struct node * ptr_to_succ)
{
	if(ptr->left_child!=NULL)
		ptr_to_succ->left_child=ptr->left_child;
	else
		ptr_to_succ->left_child=NULL;
		
	if(ptr->right_child!=NULL)
		ptr_to_succ->right_child=ptr->right_child;
	else
		ptr_to_succ->right_child=NULL;

	if(ptr->parent!=NULL)
	{	
		ptr_to_succ->parent=ptr->parent;
		
 		if(ptr->parent->left_child==ptr)
			ptr->parent->left_child=ptr_to_succ;
		else
			ptr->parent->right_child=ptr_to_succ;

	}
	else
		root=ptr_to_succ ;
	

}



void delete_node(struct node * ptr)
{
	//if ptr has no child nodes
	if(ptr->left_child==NULL && ptr->right_child==NULL)
	{
		if(ptr->parent==NULL)
		{
			root=NULL;
			free(ptr);
			puts("Node deleated");
			return;
		}
		if(ptr->parent->left_child==ptr)
			ptr->parent->left_child=NULL;
		else if(ptr->parent->right_child==ptr)
			ptr->parent->right_child=NULL;
		free(ptr);
		puts("Node deleated");
		
	}
	//if ptr has only right child
	else if(ptr->right_child!=NULL && ptr->left_child==NULL)
		spliceOut(ptr,ptr->right_child);
	//if ptr has only left child
	else if(ptr->right_child==NULL && ptr->left_child!=NULL)
		spliceOut(ptr,ptr->left_child);
	//if ptr has both child nodes
	else
	{
		struct node * temp,* ptr_to_succ;
		temp=successor(ptr);
		while(temp!=NULL)
		{
			//if successor has only right child
			if(temp->left_child==NULL && temp->right_child!=NULL)
			{
				ptr_to_succ=temp;
				spliceOut(temp,temp->right_child);
				break;
			
			}
			//if successor has only left child
			else if(temp->left_child!=NULL && temp->right_child==NULL)
			{
				ptr_to_succ=temp;
				spliceOut(temp,temp->left_child);
				break;
			
			}
			else//if sucessor node has no child nodes
			{
				ptr_to_succ=temp;
				if(temp->parent->left_child==temp)
				{
					temp->parent->left_child=NULL;
					break;
				}
				else
				{
					temp->parent->right_child=NULL;
					break;
				}
			
			}
		}
		if(temp==NULL)
			puts("no successor found");	
		else
		{
			replace_node(ptr,ptr_to_succ);
		}
		
	}

}

//====Modules for Node Delete in BST ================================================================//



//====Modules for Sum of values of all children in BST ================================================================//
int sum_children(struct node * n)
{
	int s_left=0,s_right=0;
	if(n==NULL)
		return 0;

	s_left=sum_children(n->left_child);
	s_right=sum_children(n->right_child);
	return (n->key+s_left+s_right);
}
//====Modules for Sum of values of all children in BST ================================================================//