#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a==1)
    {
        if(b==1)
            cout<<"Draw";
        else
            cout<<"Alice";
    }
    else if(b==1)
    {
        if(a==1)
            cout<<"Draw";
        else
            cout<<"Bob";
    }
    else if(a>b)
        cout<<"Alice";
    else if(a<b)
        cout<<"Bob";
    else
        cout<<"Draw";
    return 0;
}
