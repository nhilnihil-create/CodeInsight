#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e4+4;
ll n,p[N],a[N],b[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>p[i];
    for(ll i=1;i<=n;i++)a[i] = i*(n+2);
    for(ll i=1;i<=n;i++)b[p[i]]=1e9 - a[p[i]]+i;
    for(ll i=1;i<=n;i++)cout<<a[i]<<" ";cout<<"\n";
    for(ll i=1;i<=n;i++)cout<<b[i]<<" ";cout<<"\n";
}

