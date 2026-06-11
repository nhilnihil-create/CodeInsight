#pragma GCC optimize("Ofast")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
typedef pair<P,long double> Pi;
typedef pair <long double,int> Pd;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,a,b;
cin>>n>>a>>b;
vector<ll> h(n);
ll sum=0;
for(int i=0;i<n;i++){cin>>h[i];sum+=h[i];}
ll l=-1,r=(1<<30);
while(r-l>1){
  ll mid=(l+r)/2;
  ll tmp=a-b;
  ll need=0;
  for(int i=0;i<n;i++){
    if(h[i]-b*mid<=0)continue;
    need+=(h[i]-b*mid+tmp-1)/tmp;
  }
  if(need<=mid)r=mid;
  else l=mid;
}
cout<<r<<endl;
}

