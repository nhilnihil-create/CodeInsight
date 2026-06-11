#include <iostream>
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
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) {
        cin >> a[i];
        cin >> b[i];
    }
    ll add_num = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    rep(i, n) {
        if ( b[i] == 1LL ) continue;
        if ( ( a[i] + add_num ) % b[i] == 0LL ) continue;
        add_num += b[i] - ( a[i] + add_num ) % b[i];
    }
    cout << add_num << endl;
    return 0;
}
