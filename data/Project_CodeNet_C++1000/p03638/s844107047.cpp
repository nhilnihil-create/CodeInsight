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
using namespace std;
#define i64  long long
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
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return;std::cout << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class X> void DEBUG(X d, T e){if(DEBUG_OUT == false)return;std::cout <<d<<" ";DEBUG(e);};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

//CODE

void solve(void)
{
  int H,W;
  cin>>H>>W;
  int C;
  cin>>C;
  vector<int> color(C);
  for (int i = 0; i < C; i++)
  {
    cin>>color[i];
  }
  vector<vector<int> > GRID(H,vector<int>(W,0));
  bool rev = 0;
  int cpos = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      int Curent_Color = cpos;
      Curent_Color++;
      color[cpos]--;
      if(rev == 0)
      {
        GRID[i][j] =Curent_Color;
      }
      else
      {
        GRID[i][W-j-1] = Curent_Color;
      }
      if(color[cpos] == 0)cpos++;

    }
    rev ^=1;
    
  }
  
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if(j!=0)cout<<" ";
      cout<<GRID[i][j];
    }
    cout<<endl;
    
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
