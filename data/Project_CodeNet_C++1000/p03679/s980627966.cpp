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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll x, a, b;
    cin >> x >> a >> b;
    if ( b - a > x ) {
        cout << "dangerous" << endl;
    }
    else if ( b - a <= 0) {
        cout << "delicious" << endl;
    }
    else {
        cout << "safe" << endl;
    }
    return 0;
}
