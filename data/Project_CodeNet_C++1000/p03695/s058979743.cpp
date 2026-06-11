#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int, int> mp;
  int maxans = 0;
  for(int i=0; i<n; ++i){
    int x;
    cin >> x;
    if(x >= 3200) ++maxans;
    else ++mp[x/400];
  }
  if(mp.size() == 0) cout << 1 << " " << maxans << endl;
  else cout << mp.size() << " " << mp.size()+maxans << endl;
}