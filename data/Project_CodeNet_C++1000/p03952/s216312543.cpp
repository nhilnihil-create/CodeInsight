#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,x;cin>>n>>x;
    if(x==1 || x==2*n-1)return cout<<"No" , 0;
    cout<<"Yes\n";
    vector< ll > ans(2*n-1);
    for(ll i=0;i<2*n-1;i++)ans[i]=i+1 ;
    swap(ans[x-1],ans[n-1]);
    swap(ans[0],ans[n-2]);
    swap(ans[2*n-2],ans[n]);
    for(ll i=0;i<2*n-1;i++)cout<<ans[i]<<"\n";
}

