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
#define MEM_SIZE 500010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()


template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

void solve(void)
{
  int n,k;
  cin>>n>>k;
  vector<int> a1 (n+1,0);
  for (int i = 0; i < n; i++)
  {
    cin>>a1[i+1];
  }
  n++;
  vector<int> b(n,0);
    for (int i = 0; i < n-1; i++)
  {
    a1[i+1] += a1[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    b[i] = a1[i] -i*k;
  }


  auto c = b;
  sort(ALL(c));
  vector<int> d;
  d.push_back(c[0]);
  map<int,int> mp;
  mp[c[0]] = 1;
  int cnt = 2;
  for (int i = 1; i < n; i++)
  {
    if(d.back() == c[i])continue;
    else 
    {
      d.emplace_back(c[i]);
      mp[c[i]] = cnt;
      cnt++;
    }
  }
  
  BinaryIndexedTree<int> BT(MEM_SIZE);
  int res = 0;
  // BT.add(0 + MEM_SIZE/2,1);
  for (int i = 0; i < n; i++)
  {
    int x = mp[b[i]];
    // DEBUG(b[i],x);

    res += BT.sum(x +MEM_SIZE/2);
    // DEBUG(res);
    BT.add(x+ MEM_SIZE/2,1);
  }
  cout<<res<<endl;
  return ;
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
