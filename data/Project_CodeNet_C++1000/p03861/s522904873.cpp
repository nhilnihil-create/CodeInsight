#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c;
    ll ans=0;
    cin>>a>>b>>c;
    if (a%c==0){
        cout<<b/c-a/c+1;
    }
    else{
        cout<<b/c-a/c;
    }
    
}