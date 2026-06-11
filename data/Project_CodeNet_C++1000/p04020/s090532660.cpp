#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  int n, i;
  ll ans = 0;
  vector<ll> a;

  cin >> n;
  a.resize(n);

  for(i=0;i<n;i++) cin >> a[i];

  for(i=0;i<n-1;i++){
    ans += a[i]/2;

    if(a[i]%2==1&&a[i+1]!=0){
      ans += 1;
      a[i+1] -= 1;
    }
  }
  ans += a[n-1] / 2;

  cout << ans << endl;

  return 0;
}
