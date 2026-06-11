#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P> > vec;
// vector<vector<int>> data(3, vector<int>(4));

const string YES = "YES";
const string NO = "NO";

void solve(long long N, long long A, long long B, long long C, long long D) {
    bool flg = false;
    rep(i, N) {
        if (i * C - (N - 1 - i) * D + A <= B && B <= i * D - (N - 1 - i) * C + A) flg = true;
    }
    if (flg)
        cout << YES << endl;
    else
        cout << NO << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long C;
    scanf("%lld", &C);
    long long D;
    scanf("%lld", &D);
    solve(N, A, B, C, D);
    return 0;
}
