#include<iostream>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n;
    x=n/10;
    y=n%10;
    if(x==9||y==9)
    cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
