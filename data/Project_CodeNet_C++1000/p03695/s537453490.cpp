#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define all(a) a.begin(), a.end() 
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  int free = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if(a >= 3200) ++free;
    else ++mp[a/400];
  }
  
  int small = mp.size();
  if(small==0) cout << 1 << " ";
  else cout << small << " ";
  
  int large = small+free;
  cout << large << endl;
  
  return 0;
}
