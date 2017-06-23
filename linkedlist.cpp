#include <iostream>
#include <vector>
#include <algorithm>
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
	vector<int> v;
	void nodetoarray();
	public:
	linkedlist(){ head =tail=0;}	//constructor -2 
	void addhead(int n);
	void addtail(int n);
	void removehead();
	void removetail();
	void display();
	void removenode(int n);
	void sortdisplay();
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
 void linkedlist::removenode(int n){
	 node *temp = head;
	 node *prev = 0;
	 
	 //On empty List do nothing
	 
	 if(head == 0)
	 {
	 	cout << "Empty List" <<"\n" ;
	 	return ;
	 }
	 
	 if(head->element  ==n ){																// deleting head
		removehead();
	}
	 else if(tail->element ==n){															// deleting tail 	
		 removetail();																					
	 }
	 else{
		 while(temp && temp->element !=n ){
			 prev= temp;
			 temp =temp->next;
		 }
		 if(temp){
			 prev->next = temp->next;
			 delete temp;
		 }
		 else{
			 cout<<"Not found"<<"\n";
		 }
	}
}
 void linkedlist::nodetoarray(){
	 node *temp = head;
	 for(;temp!=0;temp=temp->next){
		 v.push_back(temp->element);
	 }
 }
	 
 
 void linkedlist::sortdisplay(){
	 nodetoarray();
	 sort(v.begin(),v.end());
	 for(int i=0;i<(int)v.size();i++){
		 cout<<v[i]<<"->";
	 }
	 v.erase(v.begin(),v.end());
	 cout<<"null"<<"\n";
	 
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
		 cout<<"6 sort and display  "<<"\n";
		 cout<<"7 remove node "<<"\n";
		 cout<< "8 Exit "<<"\n";
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
			 cout<<"Sorted linked list "<<"\n";
			 ll.sortdisplay();
			 break;
			 case 7:
			 cout<<"Enter the value to delete "<<"\n";
			 cin>>val;
			 ll.removenode(val);
			 break;
			 case 8:
			 break;
		 }
	 }while(choice!=8);
 }
			 
			 
		 
		 
		
		
		
		
		
		
	
		
