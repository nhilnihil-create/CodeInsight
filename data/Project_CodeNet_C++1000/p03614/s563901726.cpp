#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;

int p[100001];

void ext(int i, int j) {
    int t = p[i];
    p[i] = p[j];
    p[j] = t;
}

int main() {
    int n;
    cin >> n;
    
    REP(i,n) cin >> p[i+1];
    int cnt = 0;
    for (int i = 1; i <= n-1; i++) {
        if (p[i] == i) {
            ext(i,i+1);
            cnt++;
        }
    }
    if (p[n] == n) cnt++;
    cout << cnt << endl;
}
