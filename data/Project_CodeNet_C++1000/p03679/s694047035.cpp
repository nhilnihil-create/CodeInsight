#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,c=0,t,a,b,s;
    cin>>a>>b>>c;
    n = c-b;
    if(c-b <= 0)
    {
        cout<<"delicious\n";
    }
    else if(n <= a)
    {
        cout<<"safe\n";
    }
    else
    {
        cout<<"dangerous\n";
    }
}
