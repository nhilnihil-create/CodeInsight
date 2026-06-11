#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, pair<ll, ll> > P3;

const ll MOD = ll(1e9 + 7);
const ll LLINF = LLONG_MAX;
const int IINF = INT_MAX;
const int MAX_N = int(3e5) + 5;
const double EPS = 1e-8;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)

int main() {
    int n, i = 0, sum = 0;
    cin >> n;
    while(sum<n){
        i++;
        sum += i;
    }
    REP(j,i){
        if(sum-n == j+1)continue;
        cout << j+1 << endl;
    }
    return 0;
}
