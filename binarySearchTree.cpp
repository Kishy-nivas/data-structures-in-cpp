#include<iostream>
using namespace std ;

class nodeClass
{
	public :
	int data ;
	nodeClass* left ;
	nodeClass* right ;
	
	nodeClass(int data) ;
	
};

nodeClass::nodeClass(int data)
{
		this->data = data ;
		left  = 0 ;
		right = 0 ;
}


class binaryTree
{
	public :
	static nodeClass* root ;

	void inOrder(nodeClass* T) ;	
	void preOrder(nodeClass* T) ;	
	void postOrder(nodeClass* T) ;			
	nodeClass* findMin(nodeClass* T) ;
	nodeClass* findMax(nodeClass* T) ;
	nodeClass* insert(int data , nodeClass* T) ;
	nodeClass* del(int data , nodeClass* T) ;		
};

nodeClass* binaryTree::root = 0 ;

nodeClass* binaryTree::insert(int data , nodeClass* T)
{
	if(T == NULL)
	{
		T = new nodeClass(data) ;
		
		return T ;
	}
	
	if(data < T->data)
	{
		T->left = insert(data ,T->left) ;
	}
	else if (data > T->data)
	{
		T->right = insert(data ,T->right) ;
	}
	
	return T ;
	
	
}

nodeClass* binaryTree::del(int data , nodeClass* T)
{
	//If Null then return nothing to delete ;
	
	if(T == NULL) 
	{
		return T ;
	}
	
	if(data < T->data) 
	{
		T->left = del(data , T->left) ;
	} 
	else if(data > T->data) 
	{
		T->right = del(data , T->right) ;
	}
	else
	{
		if(T->right == NULL && T->left == NULL)
		{
			delete T ;
			T = NULL ;
		} 
		else if(T->left == NULL)
		{
			nodeClass* temp = T ;
			T = T->right ;
			delete temp ;
		}
		else if(T->right == NULL)
		{
			nodeClass* temp = T ;
			T = T->left ;
			delete temp ;
		}
		else
		{
			nodeClass* temp = findMin(T->right) ;
			T->data = temp->data ;
			T->right = del(data , T->right);
			
		}
	}
	
	return T ;

}

nodeClass* binaryTree::findMin(nodeClass* T)
{

	if(T->left != NULL)
	{
		T = findMin( T->left );
	}
	return T ;
}

nodeClass* binaryTree::findMax(nodeClass* T)
{
	if(T->right != NULL)
	{
		T = findMin( T->right );
	}
	return T ;
}

void binaryTree::inOrder(nodeClass* T)
{
	if(T != NULL)
	{
		inOrder(T->left);
		cout << T->data<<"\n" ;
		inOrder(T->right);		
	}
}

void binaryTree::preOrder(nodeClass* T)
{
	if(T != NULL)
	{
		cout << T->data<<"\n" ;	
		preOrder(T->left);
		preOrder(T->right);		
	}
}

void binaryTree::postOrder(nodeClass* T)
{
	if(T != NULL)
	{
		postOrder(T->left);
		postOrder(T->right);
		cout << T->data<<"\n" ;				
	}
}

int main()
{
	binaryTree b ;

    int val,choice;
 do{
        cout<<"Enter the choices "<<"\n";
        cout<<"1 Add Element "<<"\n";
        cout<<"2 Inorder "<< "\n";
        cout<<"3 Preorder "<<"\n";
        cout<<"4 Postorder"<<"\n";
        cout<<"5 Quit"<<"\n";
        cout<<"6 Delete Node"<<"\n";        
        cout<<"7 Find Min"<<"\n";        
        cout<<"8 Find Max"<<"\n";                        
        cout<<"*********"<<"\n";
        cin>>choice;
        switch (choice) {
        case 1:
            cout<<"Enter the value "<<"\n";
            cin>>val;
            b.root = b.insert(val , b.root);
            break;
        case 2:
            cout<<"Inorder Traversal "<<"\n";
            b.inOrder(b.root);
            break;
        case 3:
        
            cout<<"Preorder Traversal "<<"\n";
            b.preOrder(b.root);
            break;
        case 4:
            cout<<"Postorder Traversal "<<"\n";
            b.postOrder(b.root);
            break;
        case 6:
            cout<<"Enter the value "<<"\n";
            cin>>val;
            b.root = b.del(val , b.root);
            break;            
        case 7:
            cout << "Minimum Element "<<b.findMin(b.root)->data<<"\n" ;
            break;            
        case 8:
            cout << "Maximum Element "<<b.findMax(b.root)->data<<"\n" ;
            break;                        
        default:
            break;
        }
    }while(choice!=5);
    	
	return 0 ;
}
