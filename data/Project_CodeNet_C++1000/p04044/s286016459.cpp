#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N, L;
  cin >> N >> L;
  
  vector<string> dict(N);
  for (ll i = 0; i < N; i++){
    cin >> dict.at(i);
  }
  
  sort(dict.begin(), dict.end());
  
  string ans = "";
  for (ll i = 0; i < N; i++){
    ans += dict.at(i);
  }
  
  cout << ans << endl;
}