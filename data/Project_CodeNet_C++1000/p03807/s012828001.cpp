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

void solve(void)
{
  int N;cin>>N;
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    int X;cin>>X;
    if(X%2 == 1)cnt++;

  }
  if(cnt%2 == 1)
  {
    cout<<"NO"<<endl;
  }
  else
  {
    cout<<"YES"<<endl;
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
