/* Lab 1
    Data Structure and Algorithms

    Operations on Stack(PUSH and POP)

    Anish Bhusal
    072BCT505
*/
#include<iostream>
#define SIZE 100 //stack max size
using namespace std;

class stack
{
private:
    int STACK[SIZE];
    int TOP;
public:
    stack()
    {
        TOP=-1; //header(pointer) of stack
    }
    bool isEmpty(); //checks for stack underflow
    bool isFull(); //checks for stack overflow
    void push(int x); //push operation to stack
    void showElements(); //display elements of stack
    void pop(); //deletion operation to stack
};

int main()
{
    stack s;
    cout<<"-------Adding elements to the stack-------"<<endl;
    s.push(9);
    s.push(3);
    s.push(4);
    s.push(2);
    cout<<"*****Displaying elements of the stack******"<<endl;
    s.showElements();
    cout<<"***Deleting items from the stack***"<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    return 0;

}
bool stack::isFull()
{
    if(TOP==SIZE-1)
        return true;
    else
        return false;
}
void stack::push(int x)
{
    if(isFull())
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        STACK[++TOP]=x;
    }
}
void stack::showElements()
{
    for(int i=TOP; i>=0; i--)
    {
        cout<<"| "<<STACK[i]<<" |"<<endl;
    }
}
bool stack::isEmpty()
{
    if(TOP<0)
        return true;

    else
        return false;
}
void stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow:Stack Empty"<<endl;
    }
    else
    {

        cout<<"The deleted item is "<<STACK[TOP--]<<endl;

    }
}

