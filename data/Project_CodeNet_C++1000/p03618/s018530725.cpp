#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
map<char,ll> mp;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 string s; 
 cin>>s;
 ll n=s.size();
 for(int i=0;i<n;i++){
     mp[s[i]]++;
 }
 ll ma=n*(n-1)/2;
 ll same=0;
 for(char c='a';c<='z';c++){
     same+=mp[c]*(mp[c]-1)/2;
 }
 cout<<ma-same+1<<endl;
}