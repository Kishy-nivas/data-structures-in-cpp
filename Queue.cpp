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
}

int Queue::topelement(){
    return front->element;
}
int Queue::endelement(){
    return end->element;
}
bool Queue::isempty(){
    return front==0;
}
int main(){
    int val,choice;
    Queue q;
    do{
        cout<<"Enter the choices "<<"\n";
        cout<<"1 .Queue "<<"\n";
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
            if(!q.isempty()){
                q.dequeue();
            }
            else
                cout<<"Queue is empty "<<"\n";
            break;
        case 3:
            if(!q.isempty()){
                cout<<q.topelement()<<"\n";
            }
            else
                cout<<"Queue is empty"<<"\n";
            break;
        case 4:
            if(!q.isempty()){
                 cout<<q.endelement()<<"\n";
            }
            else
                cout<<"Queue is empty"<<"\n";
            break;
        default:
            break;
        }
    }while(choice!=5);
}
