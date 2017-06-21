#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<class T> 
class node {
	public:
	T element;
	node *next;
	node (T data, node *ptr=0 ){   // constructor-1 
		element = data ;
		next = ptr;
	}
};
template<class T>
class linkedlist{
	private:
	node <T> *head;
	node <T> *tail;
	vector<T> v;
	void nodetoarray();
	public:
	linkedlist(){ head =tail=0;}	//constructor -2 
	void addhead(T n);
	void addtail(T n);
	void removehead();
	void removetail();
	void display();
	void removenode(T n);
	void sortdisplay();
};
template<class T>
void linkedlist<T>::addhead(T n){
	
	head = new node<T>(n,head);
	if(tail ==0)
	tail=head;
}
template <class T>
void linkedlist<T>::addtail(T  n){
	if (tail!=0){
		 tail -> next = new node<T>(n);
		 tail =tail-> next;
	 }
	 else{
		 head = tail = new node<T>(n);
	 }
 }
 template <class T>
 void linkedlist<T>::display(){
	 node <T>*temp = head;
	 while(temp!=0){
		 cout<<temp->element<<"->";
		 temp= temp->next;
	 }
	 cout<<"null"<<"\n";
 }
 template <class T>
 void linkedlist<T>::removehead(){
	 if(head){
		 node <T>*temp =head;
		 head = head ->next;
		 delete temp;
	 }
	 else
	 head=tail=0;
 }
 
 template<class T>
 void linkedlist<T>::removetail(){
	 if(tail){
		 node <T>*temp =head;
		 for(;temp->next!=tail;temp=temp->next);
		 delete tail;
		 tail = temp;
		 tail ->next=0;
	 }
	 else 
	 head = tail =0;
 }
 template <class T>
 void linkedlist<T>::removenode(T n){
	 node <T>*temp = head;
	 node <T>*prev = 0;
	 
	 if(head->element  ==n ){													// deleting head
		removehead();
	}
	 else if(tail->element ==n){											// deleting tail 	
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
template<class T>
 void linkedlist<T>::nodetoarray(){
	 node <T>*temp = head;
	 for(;temp!=0;temp=temp->next){
		 v.push_back(temp->element);
	 }
 }
	 
 template <class T>
 void linkedlist<T>::sortdisplay(){
	 nodetoarray();
	 sort(v.begin(),v.end());
	 for(int i=0;i<(int)v.size();i++){
		 cout<<v[i]<<"->";
	 }
	 v.erase(v.begin(),v.end());
	 cout<<"null"<<"\n";
	 
 }
