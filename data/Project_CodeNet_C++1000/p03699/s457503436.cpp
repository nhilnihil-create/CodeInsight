#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int sum = 0;
  int a[n];
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  rep(i, n){
    if(sum % 10 != 0) break;
    if(a[i] % 10 == 0) continue;
    sum -= a[i];
  }
  if(sum % 10 == 0) sum = 0;
  cout << sum << endl;

       

  return 0;
}