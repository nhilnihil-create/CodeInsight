#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const int MAXN = 101024;

int x[MAXN];

int main() {
    int n; cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>x[i];
    }

    int sp = x[0] - 1;
    int stock = 1;
    ll res = 1;
    ll mod = pow(10, 9) + 7;
    for(int i = 1; i < n; ++i) {
        ++stock;
        sp += x[i] - x[i-1] - 1;
        if(stock > sp + 1) {
            res = (res * stock) % mod;
            --stock;
            ++sp;
        }
    }

    for(int i = 0; i < stock; ++i) {
        res = (res * (stock - i)) % mod;
    }

    cout << res << endl;

    return 0;
}
