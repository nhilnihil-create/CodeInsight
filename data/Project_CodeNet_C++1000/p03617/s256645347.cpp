#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll q, h, s, d;
    cin >> q >> h >> s >> d;
    int n;
    cin >> n;
    ll num1 = min({q*8, h*4, s*2, d});
    ll num2 = min({q*4, h*2, s});
    ll ans;
    if ( n&1 ) {
        cout << num1 * ( n / 2 ) + num2 << endl;;
    }
    else {
        cout << num1 * ( n / 2 ) << endl;
    }
    return 0;
}
