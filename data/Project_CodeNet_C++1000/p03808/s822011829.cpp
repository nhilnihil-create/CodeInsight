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


//BELOW
//-----CODE------//

void DFS(int v,int p,vector<vector<pair<int,int> > > & graph,vector<int> & dist)
{
  for (auto &&x : graph[v])
  {
    if(x.first == p)continue;

    dist[x.first] = dist[v]^x.second;

    // DEBUG(x.first,v,p,dist[p],dist);
    DFS(x.first,v,graph,dist);
  }
  
}

void DFS2(int v,int p,int d,int xx,vector<int> & dist,vector<vector<pair<int,int> > > & graph,map<int,int> & cnt,int &res)
{
  res += cnt[xx^d];
  for (auto &&x : graph[v])
  {
    if(x.first == p)continue;
    DFS2(x.first,v,dist[x.first],xx,dist,graph,cnt,res);
  }
  
}

  

void solve(void)
{
  int n;cin>>n;
  vector<int> vec (n,0);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
     cin>>vec[i];
     sum += vec[i];
  }  
  int k = n*(n+1)/2;
  int valid_flg = 1;
  if(sum%k != 0) valid_flg = 0;
  int cnt = sum/k;
  for (int i = 0; i < n; i++)
  {
     int b = vec[(i+1)%n] - vec[i] - cnt;
     if(b%n != 0 || b > 0)valid_flg = 0;
  }
  if(valid_flg)
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }
  
  


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
