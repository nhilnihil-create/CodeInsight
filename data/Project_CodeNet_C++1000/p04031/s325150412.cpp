#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  int ans = 1001001001;
  for(int i = -1; i <= 1; i++){
    int tmp = 0;
    for(int j = 0; j < n; j++){
      tmp += (a[j] - sum/n+i)*(a[j] - sum/n+i);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}