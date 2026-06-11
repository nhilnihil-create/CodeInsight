#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

struct subs{
  int a,b,c;
};

int main(){
  
  int n,Ma,Mb;
  cin >> n >> Ma >> Mb;
  vector<subs> v(n);
  rep(i,n)cin >> v[i].a >> v[i].b >> v[i].c;
  set<P> st;
  vector<pair<int,int>> w;
  int res = 1e9;
  for(int bit = 0;bit < (1 << (n/2));bit++){
    int a = 0,b = 0,c = 0;
    rep(i,n/2)if(bit >> i & 1)a += v[i].a,b += v[i].b,c += v[i].c;
    w.push_back(make_pair(a*Mb-b*Ma,c));
    if(a*Mb == b*Ma && a != 0)res = min(res,c);
  }
  for(int bit = 1;bit < (1 << (n-(n/2)));bit++){
    int a = 0,b = 0,c = 0;
    rep(i,(n-(n/2)))if(bit >> i & 1)a += v[i+n/2].a,b += v[i+n/2].b,c += v[i+n/2].c;
    st.insert(make_pair(-a*Mb+b*Ma,c));
  }
  for(auto au : w){
    auto iter = st.lower_bound(make_pair(au.first,0));
    if(iter != st.end() && (*iter).first == au.first)res = min(res,au.second+(*iter).second);
  }
  if(res != (int)1e9)cout << res << endl;
  else cout << -1 << endl;

  



  return 0;
}