#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N , K;
  cin >> N >> K;
  int sum = 0 ;
  for ( int i=0 ; i < N ; i++ ) {
    int x ;
    cin >> x ;
    int d ;
    int m ;
    d= min ( K-x , x ) ;
    sum += 2*d ;
  }
  cout << sum << endl;
}
