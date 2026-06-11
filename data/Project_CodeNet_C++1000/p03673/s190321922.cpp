#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  deque<int> a;
  rep(i,n) {
    int k;
    cin >> k;
    if(i%2==0) a.push_back(k);
    else a.push_front(k);
  }
  if(n%2!=0) reverse(a.begin(),a.end());
  rep(i,n) cout << a[i] << " ";
  cout << endl;
  return 0;
}
