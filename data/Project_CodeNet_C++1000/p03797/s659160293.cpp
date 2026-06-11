#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  ll n, m;
  cin >> n >> m;

  if (n * 2 > m) {
    cout << m / 2  << endl;
    return 0;
  }
  else {
    m -= n * 2;
    m /= 4;
    cout << n + m << endl;
    return 0;
  }
}
