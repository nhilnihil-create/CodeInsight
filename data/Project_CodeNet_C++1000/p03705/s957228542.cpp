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
    ll n, a, b;
    cin >> n >> a >> b;
    cout << max(0LL, ( b * ( n - 1 ) + a  ) -  ( b + a * ( n - 1 ) ) + 1 ) << endl;
    return 0;
}
