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
  int N,W;
  cin>>N>>W;
  int NUM = 4;
  vector<vector<int> > data(NUM);
  int FW,FV;
  cin>>FW>>FV;
  data[0].push_back(FV);
  for (int i = 0; i < N-1; i++)
  {
    int A,B;
    cin>>A>>B;
    data[A - FW].push_back(B);
  }
  for (int i = 0; i < NUM; i++)
  {
    data[i].push_back(INF);
    sort(data[i].begin(),data[i].end(),std::greater<int>());
    data[i][0] = 0;
    for (int j = 0; j < data[i].size()-1; j++)
    {
      data[i][j+1] = data[i][j] +data[i][j+1];
    }
    // DEBUG(data[i]);
    
  }
  int ANS = 0;
  for (int i = 0; i <= N; i++)
  {
    if(i*FW > W || i >= data[0].size()) continue;
    for (int j = 0; j <= N; j++)
    {
      if(i*FW + j*(FW+1) > W || j >= data[1].size()) continue;
      for (int k = 0; k <= N; k++)
      {
        if(i*FW + j*(FW+1) + k*(FW+2) > W || k >= data[2].size()) continue;
        for (int l = 0; l < N; l++)
        {
          if(i*FW + j*(FW+1) + k*(FW+2) + l*(FW+3)> W || l >= data[3].size()) continue;
          if(chmax(ANS,data[0][i]+data[1][j]+data[2][k]+data[3][l]))
          {
            // cout<<data[0][i]<<" "<<data[1][j]<<" "<<data[2][k]<<" "<<data[3][l]<<endl;
          }
        }
        
      }
    }
  }
  cout<<ANS<<endl;
  
  
  
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