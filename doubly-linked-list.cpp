#include<iostream>
using namespace std ;

class node{
public:
	int data ;
	node* next;
	node* prev;
	node(int data)
	{
		this->data = data ;
		next = NULL ;
		prev = NULL ;
	}

} ;

class dll{

public:
	node* head = NULL ;
	node* tail = NULL  ;
	int len ;

dll()
{
	head = NULL ;
	tail = NULL  ;
  //maintaing size of dll helps a lot
	len = 0 ;
}

void add_front(int data)
{
	node* temp = new node(data) ;

	if(head == NULL)
	{
		head = temp ;
		tail = head ;
	}
	else
	{

		head->prev = temp ;
		temp->next = head ;
		head = temp ;
	}

	len ++ ;

}

void add_back(int data)
{
	if(head == NULL)
	{
		add_front(data) ;
		return ;
	}
	else
	{
		node* temp = new node(data) ;

		tail->next = temp ;
		temp->prev = tail ;
		tail = temp ;
	}

	len++ ;

}

void add_pos(int data , int pos)
{
	int count = 0 ;

	if(pos == 0)
	{
		add_front(data) ;
		return ;
	}
  else if(pos == len-1)
	{
		add_back(data) ;
		return ;

	} else {

		//middle

		node* prev ;
		node* curr = head ;

		while(curr != NULL)
		{

			if(pos == count)
			{
				node* temp = new node(data) ;

				temp->next = curr ;
				temp->prev = prev ;

				curr->prev = temp ;
				prev->next = temp ;
				break ;

			}

			count++ ;
			prev = curr ;
			curr = curr->next ;

		}

	}

	len++ ;
}



void traverse()
{
	node* temp = head;

	while(temp != NULL)
	{

		cout << temp->data<<" " ;
		temp = temp->next ;
	}
	cout<<endl ;

}

void traverse_reverse()
{
	node* temp = tail;
	while(temp != NULL)
	{

		cout << temp->data<<" " ;
		temp = temp->prev ;
	}
	cout<<endl ;
}



} ;
int main()
{

	dll l ;

  l.add_back(45) ;
  l.add_front(46) ;
  l.add_front(55) ;


	l.traverse() ;
	l.traverse_reverse() ;

	return 0 ;
}
