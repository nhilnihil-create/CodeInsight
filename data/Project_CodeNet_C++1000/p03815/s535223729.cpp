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
#define I64_MAX 9223372036854775807
#define INF I64_MAX/2
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




void update(vector<int> & Segtree, int k, int a,int N)
{
  k += N -1;
  Segtree[k] = a;
  while(k > 0)
  {
    k = (k-1)/2;
    Segtree[k] = min(Segtree[2*k+1],Segtree[2*k + 2]);
  }
}

int query(vector<int> & Segtree,int a, int b, int k, int l,int r)
{
  // DEBUG(k);
  if(r <= a || b <= l) return 2147483647;
  if(a <= l && r <= b) return Segtree[k];
  else
  {
    int vl = query(Segtree,a,b,k*2+1,l,(r+l)/2);
    int vr = query(Segtree,a,b,k*2+2,(l+r)/2,r);
    return min (vr,vl);
  }

  

}

void solve(void)
{
  int X;
  cin>>X;
  if( X - 1 == 0)
  {
    cout<<1<<endl;
    return;
  }
  X--;
  int Y = X/11;
  X = X%11;

  if(X < 6)
  {
    cout<<2*Y  + 1 <<endl;
  }
  else
  {
    cout<<2*Y + 2 <<endl;
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