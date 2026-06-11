#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int gcd(int x, int y){
    if (y == 0) return x;
    return gcd(y, x % y);
}

bool dfs(VI a){
    int n = a.size();
    int e = 0, o;
    REP(i,n) e += (a[i] % 2 == 0);
    if (e % 2 == 1) return true;
    o = n - e;
    if (o != 1) return false;
    REP(i,n){
        if (a[i] % 2 == 1){
            if (a[i] == 1) return false;
            a[i]--;
        }
    }
    int d = gcd(a[0],a[1]);
    REP(i,n) d = gcd(d, a[i]);
    REP(i,n) a[i] /= d;
    return dfs(a) ^ 1;
}

int main() {
    int n;
    cin >> n;
    VI a(n);
    REP(i,n) scanf("%d", &a[i]);
    sort(ALL(a));

    cout << (dfs(a) ? "First" : "Second") << endl;
    return 0;
}