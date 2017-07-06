/************************************************************
 * LAB 7
 * DATA STRUCTURE AND ALGORITHMS
 *
 * RECURSION-TOWER OF HANOI PROBLEM
 *
 *************************************************************/

#include<iostream>
using namespace std;
void toh(int n,char frompeg,char auxpeg,char topeg)
{
    if(n==1)
    {
        cout<<"Moved disc "<<n<<" from peg "<<frompeg<<" to "<<topeg<<endl;
        return;
    }
    //move disc from A to B using C as auxiliary
    toh(n-1,frompeg,topeg,auxpeg);
    //move remaining disc from A to C
    cout<<"Moved disc "<<n<<" from peg "<<frompeg<<" to "<<topeg<<endl;
    //move n-1 disc from B to C using A as auxiliary
    toh(n-1,auxpeg,frompeg,topeg);
}
int main()
{
    char A,B,C;
    int n;
    cout<<"Enter the number of discs ";
    cin>>n;
    cout<<"Enter name of source, auxiliary and destination tower ";
    cin>>A>>B>>C;
    cout<<"*********** SOLVING TOH *************"<<endl;
    toh(n,A,B,C);
    return 0;
}
