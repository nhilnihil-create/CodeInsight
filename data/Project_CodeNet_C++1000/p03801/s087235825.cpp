#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
#define MEM_SIZE 101010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()


template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }


void solve(void)
{
  //https://kmjp.hatenablog.jp/entry/2017/02/19/0900
  int n;cin>>n;
  map<int,int> mp;
  vector<int> vec(n,0);
  for (int i = 0; i < n; i++)
  {
    cin>>vec[i];
    mp[vec[i]]++;
  }
  vector<int> v;
  v.push_back(0);
  for (int i = 1; i < n; i++)
  {
    if(vec[v.back()] < vec[i]) v.push_back(i);
    // 1 2 1 3 2 4 2 5 8 1
    // => 0 1 3 5 7 8 
  }
  // DEBUG(v);
  vector<int> ret (n,0);
  for (int i = v.size() - 2 ; i >= 0; i--) 
  {
    while(mp.rbegin() ->first > vec[v[i]])
    {
      auto r = *mp.rbegin();
      mp.erase(r.first);
      ret[v[i+1]] += (r.first - vec[v[i]])*1LL*r.second;
      mp[vec[v[i]]] += r.second;
    }
  }
  for (auto &&r : mp)
  {
    ret[0] += r.first*r.second;
  }
  for (int i = 0; i < ret.size(); i++)
  {
      // if(i != 0)cout<<char(32);
      cout<<ret[i]<<endl;;
  }
  // cout<<endl;
  
  
  


  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
