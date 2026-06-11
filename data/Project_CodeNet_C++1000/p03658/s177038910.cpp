#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60; 

int main()
{
  int n,k; 
  cin >> n >> k;
  int l[n];
  rep(i,n) cin >> l[i];
  sort(l,l+n,greater<int>());
  int res = 0;
  rep(i,k)
  {
    res += l[i];
  }
  cout << res << endl;
}