#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;


    if(n==1)
    {
        if(a==b)
        cout<<"1"<<endl;
        else{
            cout<<"0"<<endl;
        }

    }
    else{
    if(a>b)
    {
        cout<<"0"<<endl;
    }
    else{
        cout<<b * (n-2) - a * (n-2) + 1<<endl;
    }
    }
}
