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
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,a,b;
cin>>n>>a>>b;
vector<ll> s(n);
for(int i=0;i<n;i++)cin>>s[i];
ll sum=0;
for(int i=1;i<n;i++){
    if((s[i]-s[i-1])*a<b)sum+=(s[i]-s[i-1])*a;
    else sum+=b;
}
cout<<sum<<endl;
}