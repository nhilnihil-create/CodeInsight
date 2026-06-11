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

template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
void warshall_floyd(Matrix< T > &g) {
  for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
      for(int j = 0; j < g.size(); j++) {
        if(g[i][k] == INF || g[k][j] == INF) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}


void solve(void)
{
  int N,M;
  cin>>N>>M;
  Matrix<int> MAT(N,vector<int>(N,INF));
  vector<vector<int> > GRAPH(M,vector<int>(3,0));
  for (int i = 0; i < M; i++)
  {
    int A,B,C;
    cin>>A>>B>>C;
    A--;B--;
    MAT[A][B] = C;
    MAT[B][A] = C;
    GRAPH[i][0] = A;
    GRAPH[i][1] = B;
    GRAPH[i][2] = C;
  }
  auto cpMAT = MAT;
  for (int i = 0; i < N; i++)
  {
    MAT[i][i] = 0;
  }

  warshall_floyd(MAT);
  int cnt = 0;
  for (int m = 0; m < M; m++)
  {
    int S = GRAPH[m][0];
    int T = GRAPH[m][1];
    int C = GRAPH[m][2];
    int check = 0;
    for (int i = 0; i < N; i++)
    {
      if(MAT[i][S] + C == MAT[i][T])check = 1;
    }
    if(check == 0)cnt++;
  }
  cout<<cnt<<endl;;
  
  
  
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
