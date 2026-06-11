#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int a[n+1];
  for(int i = 1; i <= n; i++) cin >> a[i];
  
  int i = 1, j = 1;
  int ans = 1;
  while(i <= n){
    if(a[j] == 2){
      cout << ans << endl;
      return 0;
    }
    j = a[j];
    i++;
    ans++;
  }//while
  
  cout << -1 << endl;
}
