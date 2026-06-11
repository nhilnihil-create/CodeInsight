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
//SOLVE

//-----CODE------//
void solve(void)
{ 
  int N;cin>>N;
  vector<int> vec (N,0);
  for (int i = 0; i < N; i++)
  {
     cin>>vec[i];
  }
  auto v1 = vec;
  auto v2 = vec;
  int pn = 0;
  int C1 = 0;
  for (int i = 0; i < N; i++)
  {
    static int SUM = 0;
    if(pn == 0)
    {
      SUM += v1[i];
      if(SUM <= 0)
      {
        v1[i] += -1*SUM + 1;
        C1 += abs(-1*SUM + 1);
        SUM = 1;
      }
    }
    else
    {
      SUM += v1[i];
      if(SUM >= 0)
      {
        v1[i] -= SUM +1;
        C1 += abs(SUM + 1);
        SUM = -1;
      }
    }
    pn ^=1;
  }

  pn = 1;
  int C2 = 0;
  for (int i = 0; i < N; i++)
  {
    static int SUM = 0;
    if(pn == 0)
    {
      SUM += v2[i];
      if(SUM <= 0)
      {
        v2[i] += -1*SUM + 1;
        C2 += abs(-1*SUM + 1);
        SUM = 1;
      }
    }
    else
    {
      SUM += v2[i];
      if(SUM >= 0)
      {
        v2[i] -= SUM +1;
        C2 += abs(SUM + 1);
        SUM = -1;
      }
    }
    pn ^=1;
    
  }
  // DEBUG(v1,v2);
  cout<<min(C1,C2)<<endl;
  return;
}
int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(9);
  solve();

  return 0;
}
