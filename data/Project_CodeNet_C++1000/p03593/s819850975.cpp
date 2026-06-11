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
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(),(x).end()

// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }


 

void solve(void)
{
  int H,W;
  cin>>H>>W;
  map<char,int> mp;
  int COUNT = H*W;
  for (int i = 0; i < H*W; i++)
  {
    char c ;cin>>c;
    mp[c]++;
  }

  int G1 = (H%2)*(W%2);
  int G2 = H/2 + W/2;
  int G3 = (H/2)*(W/2);
  G2 = (H*W - 4*G3 - G1);
  G2 /=2;
  // DEBUG(G1,G2,G3,"\n");

  for (auto i : mp)
  {
    int v = i.second;
    while(v>= 4&&G3 > 0)
    {
      v -= 4;
      --G3;
    }
    while(v>= 2&&G2 > 0)
    {
      v -= 2;
      --G2;
    }
     while(v == 1&&G1 > 0)
    {
      --v;
      --G1;
    }
  }
  if(G1||G2||G3)
  {
    cout<<"No"<<endl;
  }
  else
  {
    cout<<"Yes"<<endl;
  }
  


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
