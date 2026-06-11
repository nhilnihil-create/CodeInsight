#include<bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lld n,a,b;
    cin>>n>>a>>b;

    if(n==1)
    {
        if(a==b)cout<<1<<"\n";
        else cout<<0<<"\n";
        return 0;
    }

    if(b-a<0)cout<<0<<"\n";
    else if(b-a>=0)
    {
       cout<<((n-2)*(b-a))+1<<"\n";
    }
}
