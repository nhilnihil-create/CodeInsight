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
    ll a, b;
    cin >> a >> b;
    if ( a > 0 && b > 0 ) {
        cout << "Positive" << endl;
    }
    else if ( a < 0 && b < 0 ) {
        if ( abs(b-a+1) % 2 == 1 ) {
            cout << "Negative" << endl;
        }
        else {
            cout << "Positive" << endl;
        }
    }
    else {
        cout << "Zero" << endl;
    }
    return 0;
}
