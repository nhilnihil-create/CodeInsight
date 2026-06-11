#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n; cin>>n;
  int an[n]; rep(i,n) cin >> an[i];
  int cnt=0;
  
  rep(i,n) {
    int j = an[i]-1;
    if (an[j]-1 == i) cnt++;
  }
  cnt /= 2;
  cout<<cnt<<endl;
}
