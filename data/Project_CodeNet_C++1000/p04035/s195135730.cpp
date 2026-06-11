#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define rrep(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};


//////////////////////////////////////////////////



int main() {
    int n; cin >> n;
    ll l; cin >> l;
    vector<ll> a(n);
    ll _max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int b = -1;
    for (int i = 0; i < n-1; i++)
    {
        ll tmp = a[i]+a[i+1];
        if (tmp > _max) {
            b= i+1;
            _max = tmp;
        }
    }
    

    if (_max < l) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for (int i = 1; i < b; i++) {
        cout << i << endl;
    }
    for (int i = n-1; i >= b; i--)
    {
        if (a[i] == _max) break;
        cout << i << endl;
    }
    

    
    return 0;
}
