#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int a[n];
  int sum = 0;
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }
  int m;
  cin >> m;
  int b[m], c[m];
  rep(i, m) cin >> b[i] >> c[i];
  
  rep(i, m){
    cout << sum - a[b[i] - 1] + c[i] << endl;
  }
    

  return 0;
}