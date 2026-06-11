#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a+b<10)
        {
            cout<<a+b<<endl;
        }
        else if(a+b>=10)
        {
            cout<<"error"<<endl;
        }
    }
}
