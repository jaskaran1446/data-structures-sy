#include<queue>
#include<stack>
#include<iostream>
class node{
	public: node* left;
	int data;
	node* right;
	public : node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

class tree{
	node* root;
	public: tree(){
				root = NULL;
			}
			void create();
			void insert(int);
			void bfs();
			int isEmpty();
			void mirror(tree*);
			void copy(tree*);
			void inorder();
			void preorder();
			void postorder();
			void nr_inorder();
			void nr_preorder();
			void nr_postorder();
			int countLeaf();
			int countNode();
			int search(int);
			void deleteNode(int);
	private:	void inorder(node*);
				void preorder(node*);
				void postorder(node*);
				node* copy(node*,node*);
				node* mirror(node*,node*);
				int countLeaf(node*);
				int countNode(node*);
	
};

void tree::deleteNode(int n){
		node *temp, *parent=NULL, *father, *r, *son; 
		temp= root;
		while((temp->data!=n) && (temp!=NULL)){ 
			if(n<temp->data){ 
				parent=temp;
				temp=temp->left;
			} 
			else{ 
				parent=temp;
				temp=temp->right;
			}
		} 

		if(temp==NULL){ 
			std::cout<<"Number not found\n"; 
			return; 
		} 
		if(temp->left == NULL)
			r=temp->right;
		else if(temp->right==NULL)
			r=temp->left;
		else{
			father=temp; 
			r=temp->right; 
			son=r->left; 
			while(son !=NULL){
				father = r ; r = son ; son = r-> left; 
			}
			if (father != temp){
				father -> left = r -> right ; 
				r -> right = temp -> right ;
			}	
			r-> left = temp -> left ; 
		} 
		if(parent==NULL)
			root=r; 
		else{
			if (temp == parent -> left) 
				parent -> left = r; 
			else 
				parent-> right = r;
		}
		temp = NULL;
		std::cout<<"Deleted\n";
}

int tree::search(int d){
	node* t = root;
	if(isEmpty()){
		return 0;
	}
	while(t){
		if(t->data == d){
			return 1;
		}
		else
		{
			
		}
		 if(d < t->data){
			t = t->left;
		}
		else{
			t = t->right;
		}
	}
	return 0;
}

void tree::nr_postorder(){
	std::stack<node*> s1,s2;
	node* temp = root;
	s1.push(temp);
	while(!s1.empty()){
		node* t = s1.top();
		s1.pop();
		s2.push(t);
		if(t->left)
			s1.push(t->left);
		if(t->right)
			s1.push(t->right);
	}
	while(!s2.empty()){
		node* q = s2.top();
		s2.pop();
		std::cout<<q->data<<" ";
	}
}

void tree::nr_inorder(){
	std::stack<node*> s;
	node* temp = root;
	while(1){
		while(temp!=NULL){
			s.push(temp);
			temp = temp -> left;
		}
		if(s.empty()){
			break;
		}
		temp = s.top();
		s.pop();
		std::cout<<temp->data<<" ";
		temp = temp -> right;
	}
}

void tree::nr_preorder(){
	std::stack<node*> s;
	node* temp = root;
	while(1){
		while(temp!=NULL){
			std::cout<<temp->data<<" ";
			s.push(temp);
			temp = temp -> left;
		}
		if(s.empty()){
			break;
		}
		temp = s.top();
		s.pop();
		temp = temp -> right;
	}
}

int tree::isEmpty(){
	return root == NULL;
}

void tree::inorder(){
	if(!isEmpty())
		inorder(root);
	else
		std::cout<<"NULL TREE";
		
}

void tree::inorder(node* n){
	if(n->left!=NULL)
		inorder(n->left);
	std::cout<<n->data<<" ";
	if(n->right!=NULL)
		inorder(n->right);
}

void tree::preorder(){
	if(!isEmpty())
		preorder(root);
	else
		std::cout<<"NULL TREE";
		
}

void tree::preorder(node* n){
	std::cout<<n->data<<" ";
	if(n->left!=NULL)
		preorder(n->left);
	if(n->right!=NULL)
		preorder(n->right);
}

void tree::postorder(){
	if(!isEmpty())
		postorder(root);
	else
		std::cout<<"NULL TREE";
		
}

void tree::postorder(node* n){
	if(n->left!=NULL)
		postorder(n->left);
	if(n->right!=NULL)
		postorder(n->right);
	std::cout<<n->data<<" ";
}

int tree::countNode(){
	return countNode(root);
}

int tree::countLeaf(){
	return countLeaf(root);
}

void tree::insert(int d){
	node* newn = new node(d);
	node* t = root;
	if(isEmpty()){
		root = newn;
		return;
	}
	while(1){
		if(d < t->data){
			if(t->left == NULL){
				t->left = newn;
				break;
			}
			else{
				t = t->left;
			}
		}
		else{
			if(t->right == NULL){
				t->right = newn;
				break;
			}
			else{
				t = t->right;
			}
		}
	}
	std::cout<<"Inserted\n";
}

void tree::create(){
	node* temp;
	while(1){
		int d;
		std::cout<<"Enter data\t";
		std::cin>>d;
		node* newn = new node(d);
		if(!root)
			temp = root = newn;
		else{
			temp=root;
			while(1){
				if(d<temp->data)
					if(!temp->left)	{
						temp->left = newn;
						break;
					}
					else
						temp = temp->left;
				else
					if(!temp->right)	{
						temp->right = newn;
						break;
					}
					else
						temp = temp->right;
			}	
		}
		std::cout<<"Enter 1 to create more\t";
		std::cin>>d;
		if(d!=1)	
			break;
	}
}

void tree::bfs(){
	node* temp = root;
	node* dummy = NULL;
	std::queue<node*> q;
	q.push(temp);
	q.push(dummy);
	while(1){
		temp = q.front();
		q.pop();
		if(temp)
			std::cout<<temp->data<<"\t";
		if(temp){
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		else{
			if(!q.empty()){
				q.push(dummy);
				std::cout<<"\n";
			}
			else
				break;
		}
	}
}

void tree::copy(tree* newt){
	newt->root = copy(root,newt->root);
}

node* tree::copy(node* t1,node* t2){
	if(t1){
		t2 = new node(t1->data);
		t2->left = copy(t1->left,t2->left);
		t2->right = copy(t1->right,t2->right);
		return t2;
	}
	return NULL;
}

int tree::countNode(node* curr){
	static int count = 0;
	if(curr){
		if(curr->left)
			countNode(curr->left);
		if(curr->right)
			countNode(curr->right);
		count++;
	}
	return count;
}

int tree::countLeaf(node* curr){
	static int count = 0;
	if(curr){
		if(curr->left == NULL && curr->right ==NULL)
		count++;
		if(curr->left)
			countLeaf(curr->left);
		if(curr->right)
			countLeaf(curr->right);
	}
	return count;
}

void tree::mirror(tree* newt){
	newt->root = mirror(root,newt->root);
}

node* tree::mirror(node* t1,node* t2){
	if(t1){
		t2 = new node(t1->data);
		t2->left = mirror(t1->right,t2->left);
		t2->right = mirror(t1->left,t2->right);
		return t2;
	}
	return NULL;
}



int main(){
	tree t1,t2;
	int ch,n;
	do{
		std::cout<<"Enter:\n1 to create a tree\n2 to insert an element\n3 to print preorder recursively\n4 to print preorder non-recursively\n5 to print postorder recursively\n6 to print postorder non-recursively\n";
		std::cout<<"7 to print inorder recursively\n8 to print inorder non-recursively\n9 to print breadth first traversal\n10 to count nodes\n11 to count leaf nodes\n12 to copy tree\n13 to mirror tree\n";
		std::cout<<"14 to check if tree is empty\n15 to search for an element\n16 to delete an element\n17 to exit\n";
		std::cin>>ch;
		switch(ch){
			case 1:
				t1.create();
				break;
			case 2:
				std::cout<<"Enter no. to insert\t";
				std::cin>>n;
				t1.insert(n);
				break;
			case 3:
				std::cout<<"Preorder recursive:\n";
				t1.preorder();
				std::cout<<"\n";
				break;
			case 4:
				std::cout<<"Preorder non-recursive:\n";
				t1.nr_preorder();
				std::cout<<"\n";
				break;
			case 5:
				std::cout<<"Postorder recursive:\n";
				t1.postorder();
				std::cout<<"\n";
				break;
			case 6:
				std::cout<<"Postorder non-recursive:\n";
				t1.nr_postorder();
				std::cout<<"\n";
				break;
			case 7:
				std::cout<<"Inorder recursive:\n";
				t1.inorder();
				std::cout<<"\n";
				break;
			case 8:
				std::cout<<"Inorder non-recursive:\n";
				t1.nr_inorder();
				std::cout<<"\n";
				break;
			case 9:
				std::cout<<"Breadth First Traversal:\n";
				t1.bfs();
				std::cout<<"\n";
				break;
			case 10:
				std::cout<<"No. of nodes="<<t1.countNode()<<"\n";
				break;
			case 11:
				std::cout<<"No. of leaf nodes="<<t1.countLeaf()<<"\n";
				break;
			case 12:
				std::cout<<"Tree copy has been created.\n";
				t1.copy(&t2);
				std::cout<<"Inorder Traversal of copy:\n";
				t2.inorder();
				break;
			case 13:
				std::cout<<"Tree mirror has been created.\n";
				t1.mirror(&t2);
				std::cout<<"Inorder Traversal of mirror:\n";
				t2.inorder();
				break;
			case 14:
				if(t1.isEmpty()){
					std::cout<<"Empty\n";
				}
				else{
					std::cout<<"Not Empty\n";
				}
				break;
			case 15:
				std::cout<<"Enter no. to search:\t";
				std::cin>>n;
				if(t1.search(n))	std::cout<<"Found\n";
				else       std::cout<<"Not Found\n";
				break;
			case 16:
				std::cout<<"Enter no. to delete:\t";	
				std::cin>>n;
				t1.deleteNode(n);
				break;
			case 17:
				std::cout<<"End\n";
				break;
			default:
				std::cout<<"Invalid choice\n";
		}
	}while(ch!=17);
	return 0;
}
