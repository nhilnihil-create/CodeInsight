#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll x,a,b;
    cin>>x>>a>>b;
    if((b-a)<=0)
    {
        cout<<"delicious"<<endl;
    }
    else if((b-a)<=x)
    {
        cout<<"safe"<<endl;
    }
    else
    {
        cout<<"dangerous"<<endl;
    }
    return 0;
}