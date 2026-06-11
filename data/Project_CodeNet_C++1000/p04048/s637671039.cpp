#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

ll n,x,ans=0;

template <class T>
void gcd(T a,T b) {
  if(a<b) swap(a,b);
	if (b==0){
    ans-=a;
	}else{
    ans+=a/b*b*2;
    gcd(b,a%b);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>x;
  ans=n;
  gcd(x,n-x);
  cout<<ans<<endl;
}