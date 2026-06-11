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
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    int n;
    cin >> n;
    VI a(n);
    REP(i,n) a[i] = in();
    sort(ALL(a));
    reverse(ALL(a));
    a.push_back(0);
    REP(i,n){
        if (i + 1 >= a[i + 1]){
            // cout << i << endl;
            int x = 1;
            if (i + 1 > a[i + 1]) x = (a[i] - i) % 2;
            else if ((a[i] - i) % 2 == 0) x = 0;
            else{
                int j = i + 1;
                while (a[j] == i + 1){
                    j++;
                    x ^= 1;
                }
            }
            cout << (x ? "Second" : "First") << endl;
            return 0;
        }
    }

    return 0;
}
