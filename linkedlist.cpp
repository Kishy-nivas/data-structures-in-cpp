#include <iostream>
using namespace std;
class node {
	public:
	int element;
	node *next;
	node (int data, node *ptr=0 ){   // constructor-1 
		element = data ;
		next = ptr;
	}
};
class linkedlist{
	private:
	node *head;
	node *tail;
	public:
	linkedlist(){ head =tail=0;}	//constructor -2 
	void addhead(int n);
	void addtail(int n);
	void removehead();
	void removetail();
	void display();
};
void linkedlist::addhead(int n){
	
	head = new node(n,head);
	if(tail ==0)
	tail=head;
}

void linkedlist::addtail(int n){
	if (tail!=0){
		 tail -> next = new node(n);
		 tail =tail-> next;
	 }
	 else{
		 head = tail = new node(n);
	 }
 }
 void linkedlist::display(){
	 node *temp = head;
	 while(temp!=0){
		 cout<<temp->element<<"->";
		 temp= temp->next;
	 }
	 cout<<"null"<<"\n";
 }
 void linkedlist::removehead(){
	 if(head){
		 node *temp =head;
		 head = head ->next;
		 delete temp;
	 }
	 else
	 head=tail=0;
 }
 
 void linkedlist::removetail(){
	 if(tail){
		 node *temp =head;
		 for(;temp->next!=tail;temp=temp->next);
		 delete tail;
		 tail = temp;
		 tail ->next=0;
	 }
	 else 
	 head = tail =0;
 }
 int main(){
	 int choice,val;
	 linkedlist ll;
	 do{
		 cout<<"choices"<<"\n";
		 cout<<"1.Add head"<<"\n";
		 cout<<"2. Add tail"<<"\n";
		 cout<<"3.remove head"<<"\n";
		 cout<<"4. remove tail"<<"\n";
		 cout<<"5 display "<<"\n";
		 cout<<"6 exit "<<"\n";
		 cin>>choice;
		 switch(choice){
			 case 1:
			 cout<<"Enter the value"<<"\n";
			 cin>>val;
			 ll.addhead(val);
			 break;
			 case 2:
			 cout<<"Enter the value"<<"\n";
			 cin>>val;
			 ll.addtail(val);
			 break;
			 case 3:
			 ll.removehead();
			 break;
			 case 4:
			 ll.removetail();
			 break;
			 case 5:
			 cout<<"The linked list is"<<"\n";
			 ll.display();
			 break;
			 case 6:
			 break;
		 }
	 }while(choice!=6);
 }
			 
			 
		 
		 
		
		
		
		
		
		
	
		
