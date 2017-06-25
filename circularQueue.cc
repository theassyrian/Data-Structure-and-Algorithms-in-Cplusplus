/* LAB 3
 * DATA STRUCTURE AND ALGORITHMS
 *
 * CIRCULAR QUEUE IMPLEMENTATION IN C++
 *
 */
#include<iostream>
#define SIZE 100
using namespace std;
class Queue{
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
    void enQueue(int n);
    bool isEmpty();
    int deQueue();
    void showElements();
};
bool Queue::isFull()
{
    if(rear==front)
        return true;
    else
        return false;
}
void Queue::enQueue(int n)
{
    int data;
    rear=(rear+1)%SIZE;
    if(isFull())
        cout<<"Queue is full: can't add"<<endl;
    else
        data=n;
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    Q[rear]=data;
}
bool Queue::isEmpty()
{
    if(front==-1)
        return true;
    else
        return false;
}
int Queue::deQueue()
{
    int data;
    if(isEmpty())
        cout<<"Queue is Empty:cannot delete more"<<endl;
    else
        data=Q[front];
    if(rear==front)
    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%SIZE;
    return data;
}
void Queue::showElements()
{
    int n;
    n=rear;
    for(int i=front;i<=rear;i++)
    {
        cout<<Q[i]<<endl;
    }
}
int main()
{
    Queue q;
    cout<<"*********Adding elements to the circular queue**************"<<endl;
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(1);
    q.enQueue(9);
    q.enQueue(0);
    q.enQueue(10);
    cout<<endl<<"***********Displaying elements of circular queue(front to rear)*********"<<endl;
    q.showElements();
    cout<<"***********Popping some elements********"<<endl;
    cout<<q.deQueue()<<" popped"<<endl;
    cout<<q.deQueue()<<" popped"<<endl;
    cout<<q.deQueue()<<" popped"<<endl;
    cout<<"*********Displaying remaining elements in Queue**********"<<endl;
    q.showElements();
    cout<<"*********Adding new elements***********"<<endl;
    q.enQueue(83);
    q.enQueue(75);
    cout<<"********Listing elements in queue*********"<<endl;
    q.showElements();
    return 0;
}
