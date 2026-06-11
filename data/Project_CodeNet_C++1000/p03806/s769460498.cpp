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

// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){std::cout << e << std::endl;}
template<class T> void DEBUG(string str, T e){std::cout <<str << ">>" << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ DEBUG(v); } }
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }


void solve(void)
{
  
  //dp[i][ca][cb] := 1{i番目までの薬品の組み合わせで、物質Aがcaグラム、物質Bがcbグラムとなる溶液の最小コスト
  int N,Ma,Mb;
  cin>>N>>Ma>>Mb;
  vector<vector<int> > DATA(N,vector<int>(3));
  for (int i = 0; i < N; i++)
  {
    cin>>DATA[i][0]>>DATA[i][1]>>DATA[i][2];
  }
  int N_MAX = 40;
  int M_MAX = 10;

  vector<vector<vector<int> > > DP(N+1,vector<vector<int> > (N_MAX*M_MAX+1,vector<int>(N_MAX*M_MAX+1,INF)));
  DP[0][0][0] = 0;

  for (int i = 0; i < N; i++)
  {
    for (int b = 0; b < N_MAX*M_MAX; b++)
    {
      for (int a = 0; a < N_MAX*M_MAX; a++)
      {
        if(DP[i][b][a] == INF) continue;
        DP[i+1][b][a] = min (DP[i+1][b][a],DP[i][b][a]);
        DP[i+1][b + DATA[i][1]][a + DATA[i][0]] = min(DP[i+1][b + DATA[i][1]][a + DATA[i][0]],DP[i][b][a] + DATA[i][2] );
      } 
    }
  }
  
  int ANS = INF;
  // DEBUG(DP[N]);
  for (int a = 1; a <  N_MAX*M_MAX; a++)
  {
    for (int b = 1; b <  N_MAX*M_MAX; b++)
    {
      if(Mb*a == Ma*b) ANS = min(ANS,DP[N][b][a]);
    }
  }
  cout<<((ANS == INF)?-1:ANS)<<endl;
  

  
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