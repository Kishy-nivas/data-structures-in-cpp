#include <iostream>

using namespace std;
template<class T>
class Stack{
private:
    T element;
    Stack *top;
    Stack *next;
public:
    Stack(){            //constructor -1
        top =0;
        next=0;
    }
    Stack(T n){       //constructor -2
        element = n;
    }

    void push(T n);
    void pop();
    T topelement();
    bool isempty();

};
template <class T>
void Stack<T>::push(T n){
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
template<class T>
void Stack<T>::pop(){
        Stack* temp;
        temp = top;
        top = top->next;
        delete temp;
    }

template <class T>
T Stack<T>::topelement(){
    return top->element;
}
template<class T>
bool Stack<T>::isempty(){
    return top==0;

}
