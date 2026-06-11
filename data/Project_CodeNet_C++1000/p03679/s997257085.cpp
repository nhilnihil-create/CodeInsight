#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x,a,b,d;
    cin>>x>>a>>b;
    if(a>=b)
        cout<<"delicious"<<endl;
    else 
    {
        d=b-a;
        if(d>x)
            cout<<"dangerous"<<endl;
        else
            cout<<"safe"<<endl;
    }
}
