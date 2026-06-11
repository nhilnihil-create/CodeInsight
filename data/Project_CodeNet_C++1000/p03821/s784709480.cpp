#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<long long>a(n),b(n);
  long long ans = 0ll;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    cin >> b.at(i);
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for(int i = 0; i < n; i++){
    a.at(i) += ans;
    if(a.at(i) % b.at(i) == 0) continue;
    ans += b.at(i) - a.at(i) % b.at(i);
    a.at(i) += ans;
  }
  cout << ans;
}
  