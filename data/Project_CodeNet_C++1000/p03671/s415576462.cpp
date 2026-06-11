#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
  int a,b,c;
  cin >> a >> b >> c;
  cout << a+b+c-max({a,b,c}) << endl;

  return 0;
}