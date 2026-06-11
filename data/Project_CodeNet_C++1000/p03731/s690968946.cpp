#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {

  long long N, T;
  long long t[N];
  cin >> N >> T;
  for ( int i=0; i<N; i++ ) {
    cin >> t[i]; 
  }
  long long sum_t = 0;
  long long limit_old = 0;
  long long limit = 0;
  long long now = 0;
  for ( int i=0; i<N; i++ ) {
    now = t[i];
    limit_old = limit;
    limit = now + T;
    if ( now > limit_old ) {
      sum_t += T;
    } else {
      sum_t += (limit - limit_old);
    }
  }

  cout << sum_t << endl;
 
  return 0;
}