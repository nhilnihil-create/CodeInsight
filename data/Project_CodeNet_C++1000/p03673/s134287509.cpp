#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <deque>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n , x;
    cin >> n;
    deque < ll > b;
    for( int i = 0 ; i < n ; i++ ){
      cin >> x;
      if( i % 2 == 1 ) b.push_front( x );
      else b.push_back( x );
    }
    if( n % 2 == 1 ) reverse( b.begin() , b.end() );
    for( int i = 0 ; i < n ; i++ )cout << b[i] << " ";
}
