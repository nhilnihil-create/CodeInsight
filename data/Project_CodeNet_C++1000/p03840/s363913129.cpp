#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll i,o,t,j,l,s,z;
    cin>>i>>o>>t>>j>>l>>s>>z;
    if(i&&j&&l) cout<<o+max(i/2*2+j/2*2+l/2*2,(i-1)/2*2+(j-1)/2*2+(l-1)/2*2+3);
    else cout<<o+i/2*2+j/2*2+l/2*2;
}