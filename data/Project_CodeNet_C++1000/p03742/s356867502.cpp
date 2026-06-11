#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll x,y;
    cin>>x>>y;
    if(abs(x-y)<=1)
    {
        cout<<"Brown";
    }
    else
    {
        cout<<"Alice";
    }
}