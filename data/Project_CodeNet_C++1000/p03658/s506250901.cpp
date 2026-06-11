#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, K, l[110], count=0, A=0, B=0;
  
  cin >> N >> K;
  rep(i,N) cin >> l[i];
  
  sort(l,l+N,greater<int>());
  
  rep(i,K) count+=l[i];
  
  cout << count;
}
