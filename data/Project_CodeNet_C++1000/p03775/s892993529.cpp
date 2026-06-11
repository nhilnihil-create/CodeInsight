#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  long long n, result=0, minimum=10; cin >> n;
  for(long long i=1;i<n;i++){
    if(to_string(i).size() > to_string(n/i).size()) break;
    if(i*(n/i) == n) result = max(to_string(i).size(), to_string(n/i).size());
    minimum = min(minimum, result);
  }
  if(n < 10) cout << 1 << endl;
  else cout << minimum << endl;
  return 0;
}
