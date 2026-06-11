#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N){cin >> vec.at(i); vec.at(i)--;}
  
  int cur=0;
  int ans=0;
  rep(i,N+10){
    cur=vec.at(cur);
    ans++;
    if (cur == 1) {cout << ans << endl; return 0;}
  }
  cout << -1 << endl; 
  return 0;
}