#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> ab;
  ab.resize(n*m);
  rep(i,2*m) cin >> ab[i]; 

  for(int i = 1; i <= n; i++){
    cout << count(ab.begin(),ab.end(),i) << endl;
  }
}