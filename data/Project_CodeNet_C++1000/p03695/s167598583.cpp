#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define ocut cout
#define ouct cout
#define itn int

struct Union{
  vector<ll> par;
  Union(ll a){
  par=vector<ll>(a,-1);
  }
  ll find(ll a){
    if(par[a]<0){
      return a;
    }
    else{
      return par[a]=find(par[a]);
    }
  }
  bool same(ll a,ll b){
    return (find(a)==find(b));
  }
  ll size(ll a){
    return -par[find(a)];
  }
  void unite(ll a,ll b){
    ll c=find(a),d=find(b);
    if(c==d)
      return;
    if(size(c)<size(d)){
      swap(c,d);
    }
    par[c]+=par[d];
    par[d]=c;
  }
};
ll euclidean_gcd(ll a, ll b) {
  if(a < b) return euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
ll euclidean_lcm(ll a, ll b) {
  return a/euclidean_gcd(a,b)*b;
}

ll binary(ll bina){
    ll ans = 0;
    for (ll i = 0; bina>0 ; i++)
    {
        ans += bina%2;
        bina = bina/2;
    }
    return ans;
}
void revStr(char* str){
	int size = strlen(str);
	int i,j;
	char tmp = {0};
	
	for(i = 0, j = size - 1; i < size / 2; i++, j--){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	return;	
}
int main(void){
  ll n;
  cin >> n;
  ll a[n],b[13];
  rep(i,13){
    b[i]=0;
  }
  rep(i,n){
    cin >> a[i];
    b[a[i]/400]++;
  }
  ll ans=0;
  rep(i,8){
    if(b[i]>0)ans++;
  }
  cout << max((ll)1,ans) << " ";
  ans=ans+b[8]+b[9]+b[10]+b[11]+b[12];
  cout << ans;
}