#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include<limits.h>
#include<float.h>
#include<list>
#include <array>
#include <complex>
#include<stdio.h>
#include<string.h>
#include <bitset>
#include<assert.h>

using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
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
  int N;cin>>N;
  vector<int> vec (N,0);
  for (int i = 0; i < N; i++)
  {
     cin>>vec[i];
  }  
  int MAX = -1;
  int MIN = INF;
  for (int i = 0; i < N; i++)
  {
    chmax(MAX,vec[i]);
    chmin(MIN,vec[i]);
  }

  if(MAX - MIN >=  2)
  {
    cout<<"No"<<endl;
    return;
  }
  // DEBUG(MAX,MIN);

  if(MAX - MIN == 0)
  {
    int SAME = 1;
    for (int i = 0; i < N; i++)
    {
      if(vec[i] != N -1) SAME = 0;
    }
      if(SAME == 1)
      {
        cout<<"Yes"<<endl;
        return;
      }

      if(2*MAX <= N)
      {
        cout<<"Yes"<<endl;
        return;
      }

      cout<<"No"<<endl;
      return;
    
  }

  if(MAX - MIN == 1)
  {
    int x = 0,y = 0;
    for (int i = 0; i < N; i++)
    {
      if(MAX -1 == vec[i]) x++;
      else y++;


    }
      if(x < MAX && 2*(MAX - x )<= y)
      {
        cout<<"Yes"<<endl;
        return;
      }
    cout<<"No"<<endl;
    
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
