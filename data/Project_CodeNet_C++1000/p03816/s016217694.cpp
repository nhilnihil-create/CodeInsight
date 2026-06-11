#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> count;
  for(int i=0;i<n;i++) {
    int a;
    cin >> a;
    count[a]++;
  }
  
  int even = 0;

  for(auto it = count.begin(); it != count.end(); it++) {
    if(it->second % 2 == 0) {
      it->second = 2;
      even++;
    }
    else it->second = 1;
  }

  if(even % 2 == 0) cout << count.size() << endl;
  else cout << count.size() - 1 << endl;
}