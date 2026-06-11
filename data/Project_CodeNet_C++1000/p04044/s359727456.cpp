#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll n,l;
    cin>>n>>l;
    vector<string> s(n);
    rep(0,i,n)cin>>s[i];
    sort(s.begin(),s.end());
    rep(0,i,n){
        cout<<s[i];
    }
    
}
