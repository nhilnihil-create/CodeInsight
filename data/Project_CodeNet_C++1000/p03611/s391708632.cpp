#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];

  map<int,int> mp;
  rep(i,N){
    mp[A[i]-1]++; mp[A[i]]++; mp[A[i]+1]++;
  }
  int ans = 0;
  for (auto itr : mp){
//    cout << itr.first << "-" << itr.second << endl;
      ans = max(ans, itr.second);
  }
  cout << ans << endl;
  return 0;
}