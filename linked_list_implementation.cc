/* linked_list_implementation.cc
 *
 * LAB 5
 * Data Structure and Algorithms
 *
 * Single Linked Lists Implementation in C++
 *
 * By: Anish Bhusal
 *     072BCT505
 *     IOE, Pulchowk Campus
 */
#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
class Linked
{
private:
    struct Node
    {
        int data;
        struct Node *next; //structure pointer for pointing next nodes
    }*start; //header of the lists
public:
    Linked()
    {
        start=NULL; //initially the linked list is empty
    }
    void insertbeg(int x);                           //for adding data at the beginning of the list
    void insertrandom(int x,int pos);       //for adding data at random position in the list
    void insertlast(int x);                             //insert at last position of the list
    void deletebeg();                                      //delete from the beginning of list
    void deleterandom(int pos);             //delete the element at specific location in the list
    void deletelast();                              //delete element from the last position of list
    void displaynodes();                        //displays the elements(data) in the nodes

};
int main()
{
    Linked l;
    int choice;
    char ch;
    do
    {
        cout<<"--------Single Linked List---------"<<endl;

        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at specific position"<<endl;
        cout<<"3. Insert at last position"<<endl;
        cout<<"4. Delete data at beginning of list"<<endl;
        cout<<"5. Delete the element from last"<<endl;
        cout<<"6. Delete the element at specific position"<<endl;
        cout<<"7. Display the nodes"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            int x;
            cout<<"Enter your data";
            cin>>x;
            l.insertbeg(x);
            l.displaynodes();
            break;
        case 2:
            int data,pos;
            cout<<"Enter data to insert ";
            cin>>data;
            cout<<"Enter the position in the list : ";
            cin>>pos;
            l.insertrandom(data,pos);
            break;
        case 3:
            cout<<"Enter data to be inserted";
            cin>>data;
            l.insertlast(data);
            l.displaynodes();
            break;

        case 4:
            cout<<endl<<"Before deleting"<<endl;
            l.displaynodes();
           l.deletebeg();
           cout<<endl<<"After deleting"<<endl;
           l.displaynodes();
            break;
        case 5:
            cout<<endl<<"Before deletion"<<endl;
                l.displaynodes();
                 l.deletelast();
                 cout<<endl<<"After deletion"<<endl;
                 l.displaynodes();
                 break;
        case 6:
            l.displaynodes();
           cout<<endl<<"Enter the position of node to be deleted";
           cin>>pos;
           l.deleterandom(pos);
            cout<<endl<<"After deletion"<<endl;
            l.displaynodes();
            break;
        case 7:
            l.displaynodes();
            break;
        default:
            cout<<"********Wrong Choice************"<<endl;
            break;
        }
        cout<<"Do you wish to continue(Y/N)?";
        cin>>ch;
        system("cls"); //clears the screen after each operation
    }
    while(ch=='Y'||ch=='y');
    return 0;
}
void Linked::insertbeg(int x)
{
    struct Node *tmp;
    //tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp=new struct Node ; //for memory allocation
    if(start==NULL)
    {
        tmp->data=x;
        tmp->next=NULL;
        start=tmp;
    }
    else
    {
        tmp->data=x;
        tmp->next=start;
        start=tmp;
    }


}
void Linked::insertrandom(int x,int pos)
{
    struct Node *newnode,*tmp;
    newnode=new struct Node;
    tmp=new struct Node;
    tmp=start;
    newnode->data=x;
    int count=0;
    while(count<pos)
    {
        if(tmp==NULL)
        {
            cout<<"Data less than position"<<endl;
            break;
        }
        tmp=tmp->next;
        count++;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;




}
void Linked::insertlast(int x)
{
    Node *tmp,*newnode;
    tmp=new struct Node();
    newnode=new struct Node();
    tmp=start;
    newnode->data=x;
    if(start==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        while((tmp->next)!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=newnode;
        newnode->next=NULL;
    }
}
void Linked::deletebeg()
{
    Node *tmp;
    tmp=new Node;


    if(start==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
            tmp=start;
            start=tmp->next;
    }
    delete(tmp);
}
void Linked::deleterandom(int pos)
{
    Node *tmp,*ptmp;
    tmp=new Node;
    ptmp=new Node;
    tmp=start;
    int count=0;
    while(count<pos)
    {
        if(tmp==NULL)
            cout<<"List has less no of elements than the position entered"<<endl;
        else
        {
            ptmp=tmp;
            tmp=tmp->next;
        }
        count++;
    }

    ptmp->next=tmp->next;
    delete(tmp);

}
void Linked::deletelast()
{
    Node *tmp,*ptmp;
    tmp=new Node;
    ptmp=new Node;
    tmp=start;
    int count=0,p=0;
    while((tmp->next)!=NULL)
    {
        ptmp=tmp;
        tmp=tmp->next;
        count++;
    }
    ptmp->next=NULL;


    delete(tmp);



}
void Linked::displaynodes()
{
    struct Node *tmp;
    int *p;
    tmp=new struct Node;
    tmp=start;
    cout<<"list is"<<endl;
    while(tmp!=NULL)
    {
        cout<<(tmp->data)<<"   ";
        tmp=tmp->next;

    }
}
