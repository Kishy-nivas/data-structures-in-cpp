#include <iostream>

using namespace std;
class Stack{
private:
    int element;
    Stack *top;
    Stack *next;
public:
    Stack(){            //constructor -1
        top =0;
        next=0;
    }
    Stack(int n){       //constructor -2
        element = n;
    }

    void push(int n);
    void pop();
    int topelement();
    bool isempty();
    
    //Additional Method
    void emptyStack() ;

};
void Stack::push(int n){
    if(top ){
        Stack *temp;
        temp = new Stack(n);
        temp->next = top;
        top =temp;
    }
    else{
        top = new Stack(n);
    }
}

void Stack::pop(){
        Stack* temp;
        temp = top;
        top = top->next;
        delete temp;
    }

int Stack::topelement(){
    return top->element;
}
bool Stack::isempty(){
    return top==0;

}
void Stack::emptyStack() 
{
	while(!isempty())
	{
		pop() ;
	}
}
int main(){
    Stack s;
    int choice,val;
    do{
        cout<<"Enter the choices"<<"\n";
        cout<<"1 push "<<"\n";
        cout<<"2 pop "<<"\n";
        cout<<"3 top"<<"\n";
        cout<<"4 quit "<<"\n";
        cout<<"5 Empty Stack "<<"\n";        
        cout<<"\n";
        cin>>choice;
        cout<<"\n";
        switch (choice) {
        case 1:
            cout<<"Enter the value to push "<<"\n";
            cin>>val;
           s.push(val);
            break;
        case 2:
            if(!s.isempty())
            s.pop();
            else
                cout<<"Stack is empty "<<"\n";
            break;
        case 3:
            if(!s.isempty())
           cout<< s.topelement()<<"\n";
            else
                cout<<"Stack is empty"<<"\n";
            break;
        case 4:
            break;
        case 5:
        	s.emptyStack() ;
            break;            
        }
    }while(choice!=4);

}







