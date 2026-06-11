#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
vector<ll> t;
int main(){
  int x,t;
  cin >> x >> t;
  cout << max(x - t, 0) << endl;
  return 0;
}