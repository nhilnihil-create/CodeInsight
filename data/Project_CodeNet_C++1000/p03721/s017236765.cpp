#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n , k;
    cin >> n >> k;
    ll x[100001] = {};
    for ( ll i = 0 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        x[a] += b;
    }
    ll c = 0;
    for ( int i = 0 ; i < 100001 ; i++ ){
       c += x[i];
       if( c >= k ){
         cout << i;
         return 0;
       }
    }
}