#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for(int i=0; i<n; i++){
    cin >> a[i];
    mp[a[i]] = i;
  }
  sort(a.begin(), a.end());
  for(int i=0; i<n; i++) ans += (i + mp[a[i]] ) % 2;
  cout << ans / 2 << endl;
}