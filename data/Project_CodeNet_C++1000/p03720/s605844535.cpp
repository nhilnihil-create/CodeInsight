#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for (int i = 0; i < (int)(j); i++)

int main() {
  int n, m;
  cin >> n >> m;
  
  int a[m] = {};
  int b[m] = {};
  int cnt[n] = {};
  
  rep(i, m){
  	cin >> a[i] >> b[i];
  }
  
  rep(i, m){
    cnt[a[i]-1] += 1;
    cnt[b[i]-1] += 1;
  }
  
  rep(i, n){
  	cout << cnt[i] << endl;;
  }
  
}