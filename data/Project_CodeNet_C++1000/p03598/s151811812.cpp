#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int n,k;
cin >> n >> k;
vector<int> a(n);
rep(i,n) cin >> a.at(i);

int ans = 0;
rep(i,n){
  ans += 2*min(abs(a.at(i)-0),abs(a.at(i)-k));
}
cout << ans << endl;
 }
