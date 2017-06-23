#include<iostream>
using namespace std;
class Queue{
private:
    Queue* front;
    Queue* end;
    Queue* next;
    int element;
public:
    Queue() { front =0,end=0,next=0;} // main-constructor
    Queue(int data){        //constructor-1
        element =data;

    }
    void queue(int data);
    void dequeue();
    int topelement();
    int endelement();
    bool isempty();
    
    
};
void Queue::queue(int data){
    if(front){
        Queue* temp;
        temp =new Queue(data);
        end->next =temp;
        temp->next =0;
        end =temp;

    }
    else{
        front=end=new Queue(data);

    }
}
void Queue::dequeue(){
    if(front){
        Queue *temp;
        temp = front;
        front =front->next;
        delete temp;
    }
    
    if(isempty())
    {
    	end = 0 ;
		cout << "Queue Empty"<<"\n" ;
    }
    
    
}

int Queue::topelement(){

	if(!isempty())
	{
    	return front->element;	
	}
	
	cout << "Queue Empty"<<"\n" ;
	return -1 ;
}
int Queue::endelement(){

	if(!isempty())
	{
	    return end->element;
	}
	
	cout << "Queue Empty"<<"\n" ;
	return -1 ;
}
bool Queue::isempty(){
    return front==0;
}
int main(){
    int val,choice;
    Queue q;
    do{
        cout<<"Enter the choices "<<"\n";
        cout<<"1 Queue "<<"\n";
        cout<<"2 Dequeue"<< "\n";
        cout<<"3 top element "<<"\n";
        cout<<"4 bottom element "<<"\n";
        cout<<"5 quit"<<"\n";
        cout<<"*********"<<"\n";
        cin>>choice;
        switch (choice) {
        case 1:
            cout<<"Enter the value "<<"\n";
            cin>>val;
            q.queue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout<<q.topelement()<<"\n";
            break;
        case 4:
            cout<<q.endelement()<<"\n";
            break;
        default:
            break;
        }
    }while(choice!=5);
}
