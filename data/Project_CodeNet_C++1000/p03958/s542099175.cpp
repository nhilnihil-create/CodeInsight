#include<bits/stdc++.h>
#define rep(i ,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int k,t;
  cin >> k >> t;
  vector<int> a(t);
  rep(i,t) cin >> a[i];
  
  int maxa = 0;
  rep(i,t){
    maxa = max(maxa,a[i]);
  }
  
  cout << max(0,2*maxa-1-k) << endl;
}

