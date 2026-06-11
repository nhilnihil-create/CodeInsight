#include <bits/stdc++.h>
using namespace std;
int n, a, C[100005];
int main(){
  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> a;
    C[a]++;
    C[a+1]++;
    C[a-1]++;
  }
  int ans = 0;
  for(int i=0; i<100005; ++i) ans = max(ans, C[i]);
  cout << ans << endl;
}