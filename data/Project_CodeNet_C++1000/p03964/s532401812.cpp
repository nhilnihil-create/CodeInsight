#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

typedef long long ll;

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> t(n),a(n);
    rep(i,n) cin >> t[i] >> a[i];

    rep(i,n-1)
    {
        if(t[i] > t[i+1] || a[i] > a[i+1])
        {
            ll l = ceil((long double)(t[i]) / (long double)(t[i+1]));
            ll r = ceil((long double)(a[i]) / (long double)(a[i+1]));
            ll s = max(r,l);
            t[i+1] *= s; a[i+1] *= s;
        }
    }
    cout << t[n-1] + a[n-1] << endl;
}