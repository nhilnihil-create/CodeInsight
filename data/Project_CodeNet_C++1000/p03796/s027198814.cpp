#include<iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++ i)
#define reps(i, s, n) for (int i = s; i < (n); ++ i)
#define LL long long

int main()
{
  int n;
  cin >> n;
  
  LL snuke_pow = 1;
  for (int i = 1; i < n + 1; i ++)
  {
    snuke_pow *= i;
    snuke_pow %= 1000000007LL;
  }
  
  cout << snuke_pow;

  return 0;
}