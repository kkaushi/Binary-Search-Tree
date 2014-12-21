#include<stdio.h>
#include"BST_node.c"

struct node * get_the_pointer(int val)
{
	struct node * ptr;
	if(root==NULL)
	{
		//puts("Tree Empty!!");
		return NULL;
	}
	else
		ptr=root;
	
	while(ptr->key!=val && ptr!=NULL)
	{
		if(val<ptr->key)
			ptr=ptr->left_child;
		else if(val>ptr->key)
			ptr=ptr->right_child;
	}

	if(ptr==NULL)
		return NULL;
	else
		return ptr;
}


void show_traversal_menu()
{
	int val;
	puts("\t1:Inorder\n\t2:Preorder\n\t3:Postorder\n\t4:Exit");		
	puts("Enter the choice:");
	scanf("%d",&val);
	{
		char dummy;
		scanf("%c",&dummy);
	}
	//puts("\t\t\t----------------------------BST Traversal---------------------------------");
	if(val==1)
	{
		inorder(root);
	}
	else if(val==2)
	{
		preorder(root);
	}
	else if(val==3)
	{
		postorder(root);
	}
	else
		puts("\n exiting traversal menu...");
			
}



void call_method(int ch)
{
	int key;
	struct node * temp;
	switch(ch)
	{
		case 1://insert a node
			{
				
				puts("Enter a key value");
				scanf("%d",&key);
				{
					char dummy;
					scanf("%c",&dummy);

				}
				insert_node(key);
				break;
			}
		case 2://traversal 
			{
				show_traversal_menu();
				break;
			}
		case 3:
			{
				puts("Enter the key value:");		
				scanf("%d",&key);
				{
					char dummy;
					scanf("%c",&dummy);

				}
				temp=get_the_pointer(key);
				if(temp==NULL)
				{
					puts("no successor exists"); 
					break;
				}
				temp=successor(temp);
				if(temp!=NULL)
					printf("\nThe successor of %d is %d\n",key,temp->key);
				else 
					puts("no successor exists");
				break;
			}
		case 4:
			{
				puts("Enter the key value:");		
				scanf("%d",&key);
				{
					char dummy;
					scanf("%c",&dummy);

				}
				temp=get_the_pointer(key);
				if(temp==NULL)
				{
					puts("no predecessor exists");
					break;
				}
				temp=predecessor(temp);

				if(temp!=NULL)
					printf("\nThe predecessor of %d is %d\n",key,temp->key);
				else 
					puts("no predecessor exists");
				break;
			}
		case 5:
			{
				puts("Enter the search value:");	
				scanf("%d",&key);
				{
					char dummy;
					scanf("%c",&dummy);

				}
				search(key);

				break;
			}
		case 6:	
			{
				puts("Enter the value to be deleated:");	
				scanf("%d",&key);
				{
					char dummy;
					scanf("%c",&dummy);

				}
				temp=get_the_pointer(key);
				if(temp==NULL)
					puts("NOde doesn't exists");
				else
					delete_node(temp);
				break;
			}
		case 7:
			exit();
		case 8: 
			{
				int sum=0;
				puts("Sum of all children of root is:");
				sum=sum_children(root);
				printf("%d\n",sum);
			}
			
			
	}
}

void display_menu()
{
	int val;
	puts("\t\t\t----------------------------BST------------------------------------------");
	puts("1:Insert a Node\n2:Traverse BST\n3:Sucessor of a Node\n4:Predecessor of a Node\n5:Search a Node\n6:Delete a Node\n7:Exit\n8:Sum of all children\n\nEnter your choice:");
	scanf("%d",&val);
	{
		char dummy;
		scanf("%c",&dummy);
	}
	call_method(val);

	
}


void main()
{
	/*insert_node(5);
	insert_node(15);
	insert_node(3);
	insert_node(7);
	insert_node(25);
	insert_node(4);
	puts("done");*/

	/*preorder(root);
	puts("-----------	-------------------	----------------------	----------------------");
	inorder(root);
	puts("-----------	-------------------	----------------------	----------------------");
	postorder(root);
	puts("-----------	-------------------	----------------------	----------------------");
	max_in_bst(root);
	puts("-----------	-------------------	----------------------	----------------------");
	min_in_bst(root);
	puts("-----------	-------------------	----------------------	----------------------");
	//successor(root->left_child->right_child);//4
	puts("-----------	-------------------	----------------------	----------------------");
	//successor(root->right_child->right_child);//25
	puts("-----------	-------------------	----------------------	----------------------");
	//successor(root->right_child->left_child);//7
	puts("-----------	-------------------	----------------------	----------------------");
	//successor(root->right_child);//15
	puts("-----------	-------------------	----------------------	----------------------");
	predecessor(root);//
	puts("-----------	-------------------	----------------------	----------------------");
	predecessor(root->right_child->left_child);//7
	puts("-----------	-------------------	----------------------	----------------------");
	predecessor(root->left_child);//3
	puts("-----------	-------------------	----------------------	----------------------");
	search(15);
	puts("-----------	-------------------	----------------------	----------------------");
	search(26);
	puts("-----------	-------------------	----------------------	----------------------");
	delete_node(root->left_child->right_child);
	puts("-----------	-------------------	----------------------	----------------------");
	delete_node(root);
	puts("-----------	-------------------	----------------------	----------------------");


	puts("-----------	-------------------	----------------------	----------------------");
	puts("-----------	-------------------	----------------------	----------------------");
	
	
	
	puts("-----------	-------------------	----------------------	----------------------");
	inorder(root);
	puts("-----------	-------------------	----------------------	----------------------");
	//delete_node(root->left_child);
	//delete_node(root);
	//delete_node(root->left_child->right_child);
	//delete_node(root->right_child);
	//delete_node(root->right_child->left_child);
	puts("-----------	-------------------	----------------------	----------------------");
	inorder(root);
	puts("-----------	-------------------	----------------------	----------------------");*/


	static char choice=89;
	int dataset;

	puts("Enable default data set\n1-yes\n2-no");
	scanf("%d",&dataset);

	if(dataset==1)
	{
		//default dataset
		insert_node(50);
		insert_node(45);
		insert_node(55);
		insert_node(40);
		insert_node(48);
		insert_node(52);
		insert_node(57);
	}

	while(choice ==89 || choice ==121)
	{
		
		display_menu();
		puts("Do you want to continue:(Y/y)");
		memset(&choice,' ',sizeof(char));
		
		//--------this is the only solution to receive a character via scanf-------
		scanf("%c",&choice);
		{
			char dummy;//,dummy2;
			scanf("%c",&dummy);
			//scanf("%c",&dummy2);

		}
		
			
		

	}


}