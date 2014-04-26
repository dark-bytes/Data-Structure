#include<iostream>
#include<stdlib.h>
using namespace std;

class avl{
	private:
		typedef struct node{
			int data;
			int height;
			struct node* right;
			struct node* left;
		}NODE;
						
	public:
		NODE* root;
		avl(){
			root = NULL;
		}
		
		int get_height(NODE* temp){
			if(temp == NULL)
				return -1;
			else
				return temp->height;
		}
		
		int max(int h1,int h2){
			if(h1>h2)
				return h1;
			else
				return h2;
		}
		
		NODE* insert(NODE* temp,int x){
			if(temp == NULL){
				temp = (NODE*)malloc(sizeof(NODE));
				temp->data = x;
				temp->right = NULL;
				temp->left = NULL;
				temp->height = 0;
			}
			else if(temp->data < x){
					temp->right = insert(temp->right,x);
					temp->height = 1 + max(get_height(temp->right),get_height(temp->left));
					if(get_height(temp->right) - get_height(temp->left) == 2){
						if(get_height(temp->right->left) > get_height(temp->right->right))
							double_rotation(temp,0);
						else
							single_rotation(temp,0);
					}
			}
			else if(temp->data >= x){
					temp->left = insert(temp->left,x);
					temp->height = 1 + max(get_height(temp->right),get_height(temp->left));
					if(get_height(temp->left) - get_height(temp->right) == 2){
						if(get_height(temp->left->right) > get_height(temp->left->left))
							double_rotation(temp,1);
						else
							single_rotation(temp,1);
					}
			}
			
			return temp;
		}
		void right_rotation(NODE* temp){
			int in_change = temp->data;
				temp->data = temp->left->data;
				temp->left->data = in_change;
			NODE* nod_change = temp->left;
			temp->left = temp->left->left;
			nod_change->left = nod_change->right;
			nod_change->right = temp->right; 
			temp->right = nod_change;
			temp->right->height = 1 + max(get_height(temp->right->right),get_height(temp->right->left));
			temp->height = 1 + max(get_height(temp->right),get_height(temp->left));
		}
		
		void left_rotation(NODE* temp){
			int in_change = temp->data;
				temp->data = temp->right->data;
				temp->right->data = in_change;
			NODE* nod_change = temp->right;
			temp->right = temp->right->right;
			nod_change->right = nod_change->left;
			nod_change->left = temp->left;
			temp->left = nod_change;
			temp->left->height = 1 + max(get_height(temp->left->right),get_height(temp->left->left));
			temp->height = 1 + max(get_height(temp->right),get_height(temp->left));
		}
		
		void single_rotation(NODE* temp,int flag){
			if(flag == 1)
				right_rotation(temp);
			else
				left_rotation(temp);
		}
		
		void double_rotation(NODE* temp,int flag){
			if(flag == 1){
				left_rotation(temp->left);
				right_rotation(temp);
			}
			else{
				right_rotation(temp->right);
				left_rotation(temp);
			}
		}
		
		
		void inorder_trav(node* temp){
			if(temp!=NULL){
				inorder_trav(temp->left);
				cout<<temp->data<<"  "<<temp->height<<endl;
				inorder_trav(temp->right);
			}
		}
		
};

int main(){
	avl a;
	cout<<"No. of elements u want";
	int n,ins;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>ins;
		a.root = a.insert(a.root,ins);
	}
	a.inorder_trav(a.root);
	return 0;
}
