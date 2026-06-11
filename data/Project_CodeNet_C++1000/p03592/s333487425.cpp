#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,m,k;cin>>n>>m>>k;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            ll cnt = i*(m-j) + j*(n-i);
            if(cnt==k)return cout<<"Yes" , 0;
        }
    }
    cout<<"No";
}



