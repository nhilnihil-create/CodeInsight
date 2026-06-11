#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += min(abs(k-a[i])*2,a[i]*2);
  }
  cout << ans << endl;
}