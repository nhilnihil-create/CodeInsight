#include<cstdio>
#include<iostream>
typedef long long ll;
using namespace std;
int main()
{
    ll x,y;
    cin>>x>>y;
    if(abs(x-y)<=1)
    {
        cout<<"Brown"<<endl;
    }
    else
    {
        cout<<"Alice"<<endl;
    }
}
