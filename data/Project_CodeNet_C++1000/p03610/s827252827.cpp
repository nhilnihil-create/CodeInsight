#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using lld=long double;
#define all(c) (c).begin(), (c).end()
#define rep( i, a, n ) for( int i=a; i<n; i++ )
#define repp( i, a, n, p ) for( int i=a; i<n; i+=p )
#define per( i, a, n ) for( int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define acc accumulate

int main () {
  string s;
  cin >> s;
  for ( ll i=0; i<s.size(); i++ ) { 
    if ( i % 2 == 0 ) {
      cout << s[i];
    }
  }
}

