#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60


int main() {
    int N;
    ll L;
    cin >> N >> L;

    vector<ll> a(N);
    REP(i, N) {
        cin >> a[i];
    }

    int idx = -1;
    REP(i, N-1) {
        if(a[i] + a[i+1] >= L) {
            idx = i+1;
            break;
        }
    }

    if(idx == -1) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    FOR(i, 1, idx-1) {
        cout << i << endl;
    }

    FORR(i, N-1, idx+1) {
        cout << i << endl;
    }

    cout << idx << endl;

    return 0;
}