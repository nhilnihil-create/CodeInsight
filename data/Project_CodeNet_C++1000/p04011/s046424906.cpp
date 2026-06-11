#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
int main()
{
    ll n,k,x,y;
    cin>>n>>k>>x>>y;
    if(n>=k)
    cout<<k*x+(n-k)*y<<endl;
    else
    cout<<n*x<<endl;
    return 0;
}
