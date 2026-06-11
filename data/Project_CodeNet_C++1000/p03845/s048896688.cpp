#include <bits/stdc++.h>
using namespace std;

int main() {
  int n ;
  cin >> n;
  vector < pair <int , int> > a(n);
  int sum = 0 ;
  for ( int i=0 ; i<n ; i++){
    int t ;
    cin >> t;
    a.at(i) = make_pair ( i, t);
    sum += t;
  }
  int m ;
  cin >> m;
  for ( int i=0 ; i<m ; i++) {
    int p,b,c,t , ans;
    cin >> p >> b;
    tie(c,t) = a.at (p-1) ;
    ans = sum - t + b ;
      cout << ans << endl;
  }
}