#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
int main() {
  map<int, int> mp;
  rep(i, 3){
    int s; cin >> s; mp[s]++;
  }
  if(mp[5]==2 && mp[7]==1) cout << "YES" << endl;
  else cout << "NO" << endl;
}
