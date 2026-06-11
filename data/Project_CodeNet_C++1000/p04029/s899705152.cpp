#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int a,n;
  cin >> n;
  a = 0;
  rep(i, n + 1){
    a += i;
  }
  cout << a << endl;
  return 0;
}