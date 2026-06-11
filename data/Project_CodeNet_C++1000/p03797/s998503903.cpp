#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

typedef long long ll;
#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define llrep(i,n)   for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prt_dbl(i,var) cout<<fixed<<setprecision(i)<<var<<endl;
template <typename Val>
Val gcd(Val a, Val b) {
//use ll or int for gcd
    if (b==0) return a;
    else return gcd(b, a%b);
}
template <typename Val>
Val vec_max(vector<Val> v){
  return *max_element(v.begin(),v.end());
}
template <typename Val>
Val vec_min(vector<Val> v){
  return *min_element(v.begin(),v.end());
}


//---------------------------------------------------------------

int main(){
  ll N,M,ans;
  cin>>N>>M;
  if(2*N<M){
    ans = N;
    ans+=(M-2*N)/4;
  }else if(2*N>M){
    ans = M/2;
  }else{
    ans = N;
  }
  cout<<ans<<endl;

}
