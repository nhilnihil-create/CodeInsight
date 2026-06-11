#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
using namespace std;
long long int inf = 1e18;

int main() {

  int n; cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  vector<long long int> b(n, 0);
  b[0] = a[0];
  for(int i=1; i<n; i++){
    b[i] = a[i];
    b[i] += b[i-1];
  }

  long long int ans = inf;
  for(int i=0; i<n-1; i++){
    long long int x = b[i];
    long long int y = b[n-1] - b[i];
    ans = min(abs(x-y), ans);
  }
  cout << ans << endl;



  return 0;
}
