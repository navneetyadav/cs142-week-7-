#include<iostream>
using namespace std;

class Node
	{
		public:
		
		int data;
		//children
		Node* right;
		Node* left;
		Node* parent ;
		Node(int value)
			{
			data=value;
			right=NULL;
			left=NULL;			
			parent=NULL;
			}		
	
	};

class bist{

public:

Node* root;

bist()
{
root = NULL;
}

void insert(int value)
	{
		insertHelper(root,value);
		
	}	
void insertHelper(Node * curr,int value)
				{
				//base case if curr== null,insert there
				if (root == NULL)
				{
				root = new Node(value);
				
				}
				


				//else compare the curr data with value	
                                //f curr data >value ->move to left and call insertHelper

				else if(value 	< curr->data)
						//if left is NULL,insert it
					{
					if(curr->left==NULL)
								{
								curr->left=new Node(value);
								}
					else{
					insertHelper(curr->left,value);
					}
					}		
				//else move to left and call inserthelper
				else {
					if(curr->right==NULL)
								{
								curr->right=new Node(value);
								}
					else{
					insertHelper(curr->right,value);
					}
					
				     }

				}

//finding the minimum value
	Node* fmin(int val){
		Node* curr = search(val);
		if(root==NULL||curr==NULL)
		{
		return NULL;
		}
		return fmin2(val,curr);
				}

	Node* fmin2(int val, Node* curr){
		if(curr->left==NULL)
		{
		return curr;
		}
		else{fmin2(val, curr->left);}
}



//delete function
	void Delete(int val){
		Node* curr = search(val);
		//no node case
		if(curr==NULL){
			cout << "THIS value is absent"<<endl;
		}
		else{
			count--;
			//only one kid case
			if(curr->left&&curr->right==NULL||curr->left==NULL&&curr->right){
				//left child present
				if(curr->left&&curr->right==NULL){
				Node* temp = curr->left;
					//if current is root
					if(curr==root){root=temp;}
					else{
						//curr if left or right child
						if((curr->data)<(curr->parent->data)){
							curr->parent->left=temp;}

						else{curr->parent->right=temp;}
					}
				temp->parent=curr->parent;
				}
				//right child present
				else{
					Node* temp = curr->right;
					//if current is root
					if(curr==root)
					{
					root=temp;
					}
					else{
						//Wether curr is left child or right one
						if((curr->data)<(curr->parent->data)){
							curr->parent->left=temp;
										}
						else{curr->parent->right=temp;}
					}
				temp->parent=curr->parent;
				}		
				delete curr;
				return;
			}
			//if two children present
			if(curr->left&&curr->right){
				//inorder succesor
				Node* temp = fmin(curr->right->data);
				curr->data = temp->data;
				//deleting the previous links
				//Note:- The minimum may have a right child
				if(temp->right){
					temp->parent->left=temp->right;
					temp->right->parent=temp->parent;
				}
				else{

					temp->parent->left=NULL;
				}
				delete temp;
				return;
			}
			//when there are no kids at all
			if(curr->left==NULL&&curr->right==NULL){
				//if current is root
				if(curr==root){root=NULL;}
				//deleting the previous links
				if((curr->data)<(curr->parent->data)){
					curr->parent->left=NULL;
				}
				else{curr->parent->right=NULL;}
				delete curr;
			}
		}
}














void display()															//IN ORDER,PRE ORDER POST ORDER
	{
		display2(root);
	}

void display2(Node*curr)
{

//base condition
if(curr==NULL) return;
//display left
display2(curr->left);
//display current
cout<<curr->data<<",";
//display right
display2(curr->right);
//
	}


Node displayfancy(int spaces){
//increase no. of spaces
//disp right
//print required spaces
//disp curr
//disp left
/*
		16
	14
		12
10
		8
	6
		4
			      
*/
}


Node * search(Node*curr,int value){
		//if reached the leaf or value found
		if(curr==NULL || curr->data==value) return curr;
		else if(value<curr->data)
					{
						return search(curr->left,value);
					}
		else
					{
						return search(curr->right,value);
					}

		}


//nest class
//height()
//delete node()


	   };



int main(){
 
bist obj;
obj.insert(10);
obj.insert(1);
obj.insert(12);
obj.insert(13);
obj.insert(14);
obj.insert(15);
obj.display();
Node* find = b1.search(2);
	if (find!=NULL)
			{
				cout << find->data << endl;
			}
	else
			{
				cout << "The number is not there in the tree" << endl;
			} 
	
	Node* parent = b1.fmin(4);
	cout << parent-> data << endl;
	int right = b1.Count();
	cout << "No of nodes = " << right << endl;
	b1.display();
	b1.Delete(13);
b1.display();
return 0;
}

