/* LAB 2
 * DATA STRUCTURE AND ALGORITHMS
 *
 *
 * LINEAR QUEUE IMPLEMENTATION IN C++
 *
 *
 */
#include<iostream>
#define SIZE 100
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int Q[SIZE];
public:
    Queue()
    {
        front=-1;
        rear=-1;
    }
    bool isFull();
    void push(int n);
    bool isEmpty();
    int pop();
    void showElements();

};
bool Queue::isFull()
{
    if(rear>=SIZE)
        return true;
    else
        return false;

}
bool Queue::isEmpty()
{
    if(rear==-1||rear<front)
        return true;
    else
        return false;
}
void Queue::push(int n)
{
    if(isFull())
        cout<<"Queue overflow"<<endl;
    else
        Q[++rear]=n;
}
int Queue::pop()
{
    if(isEmpty())
        cout<<"Queue Underflow"<<endl;
    else
        return Q[++front];
}
void Queue::showElements()
{
    int n;
    n=rear;
    for(int i=0;i<=n;i++)
    {
        cout<<Q[i]<<endl;
    }
}
int main()
{
    Queue q;
    cout<<"**********Adding elements to the queue***************"<<endl;
    q.push(10);  //pushes 10 to Queue by increasing rear
    q.push(12);
    q.push(9);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<"**********Displaying the items in queue from front to rear*************"<<endl;
    q.showElements();
    cout<<"**********Deleting items from the queue***********"<<endl;
    cout<<q.pop()<<" popped"<<endl;
    cout<<q.pop()<<" popped"<<endl;
    cout<<q.pop()<<" popped"<<endl;
    cout<<q.pop()<<" popped"<<endl;
    return 0;
}
