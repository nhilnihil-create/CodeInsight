#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  long long sum = 0;
  int cnt = 0, ans = n;
  for(int i = 0; i < n-1; i++){
    sum += a.at(i), cnt++;
    if(sum * 2 >= a.at(i+1)) continue;
    ans -= cnt;
    cnt = 0;
  }
  
  cout << ans << endl;
}