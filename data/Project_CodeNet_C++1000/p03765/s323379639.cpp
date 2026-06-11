#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s,t;cin>>s>>t;
    ll n=s.size(),m=t.size();
    vector<ll> a(n+1,0) , b(m+1,0);
    for(ll i=0;i<n;i++)a[i+1]=1 + (s[i]=='B');
    for(ll i=0;i<m;i++)b[i+1]=1 + (t[i]=='B');
    for(ll i=1;i<=n;i++)a[i]+=a[i-1];
    for(ll i=1;i<=m;i++)b[i]+=b[i-1];
    ll q;cin>>q;
    while(q--){
        ll l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
        if( (a[r1]-a[l1-1]+3)%3 == (b[r2]-b[l2-1]+3)%3 )cout<<"YES\n";
        else cout<<"NO\n";
    }
}