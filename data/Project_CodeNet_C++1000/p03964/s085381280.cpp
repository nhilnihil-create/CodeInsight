#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int n; cin >> n;
  vector<int> t(n), a(n);
  for(int i = 0; i < n; i++){
    cin >> t[i] >> a[i];
  }
  unsigned long long ts = t[0], as = a[0];
  for(int i = 1; i < n; i++){
    unsigned long long int x = ts / t[i];
    if(ts % t[i] != 0) x++;
    unsigned long long int y = as / a[i];
    if(as % a[i] != 0) y++;
    for(unsigned long long int j = max(x, y); ; j++){
      if(t[i] * j >= ts && a[i] * j >= as){
        ts = t[i] * j;
        as = a[i] * j;
        break;
      }
    }
    //cout << ts << " " << as << endl;
  }
  cout << ts + as << endl;
  return;
}

int main(){
  solve();
  return 0;
}
