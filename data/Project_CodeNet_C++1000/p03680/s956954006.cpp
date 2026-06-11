#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
using namespace std;

int main() {
  int N; cin >> N;
  int a[N]; rep(i,0,N) cin >> a[i];
  
  bool check[N]; rep(i,0,N) check[i] = false;
  bool right = false;
  int ans = -1,tmp =0,count =0;
  while (true) {
    if (check[tmp]) break;
    check[tmp] = true;
    if (check[1]) {
      right = true; break;
    }
    count++;
    tmp = a[tmp] - 1;
  }
    
  if (right) cout << count << endl;
  else cout << -1 << endl;
}