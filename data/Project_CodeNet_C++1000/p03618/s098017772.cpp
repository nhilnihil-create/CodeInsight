#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  
  long long l = a.size();
  map<char, long long> cnt;
  for(int i = 0; i < l; i++){
    char c = a.at(i);
    cnt[c]++;
  }
  
  long long ans = l * (l-1) / 2 + 1;
  for(auto now : cnt){
    ans -= now.second * (now.second-1) / 2;
  }
  
  cout << ans << endl;
}