#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define MOD 1000000007
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

#define int long long

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a)  begin((a)), end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

const int MAX_N = 100005;
int N, K;
int A[MAX_N];

vector<int> vec[MAX_N];
bool used[MAX_N];

int ans = 0;
int solve(int pos) {
    int ret = 0;
    for(int next : vec[pos]) {
        if(next == pos) {
            continue;
        }
        int tmp = solve(next);
        if(tmp >= K && pos != 0) {
            ans++;
        } else {
            ret = max(tmp, ret);
        }
    }
    return ret+1;
}

signed main()
{
    cin >> N >> K;
    REP(i,N) {
        cin >> A[i]; A[i]--;
    }

    if(A[0] != 0) {
        ans++;
        A[0] = 0;
    }

    FOR(i,1,N) {
        vec[A[i]].push_back(i);
    }

    solve(0);
    cout << ans << endl;

    return 0;
}