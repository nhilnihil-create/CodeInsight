#include <bits/stdc++.h>
using namespace std;

#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
const ll  INFLL = 1e18;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    vector<vector<bool>> B(N, vector<bool>(N, true));

    ll ans = 0;
    rep(i, N) rep(j, N) {
        cin >> A[i][j];
    }

    rep(k, N) rep(i, N) rep(j, N) {
        if (k == i || k == j) continue;
        if (A[i][j] > A[i][k] + A[k][j]) {
            cout << -1 << endl;
            return 0;
        }
        if (A[i][j] == A[i][k] + A[k][j]) {
            B[i][j] = false;
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (B[i][j]) ans += A[i][j];
        }
    }

    cout << ans << endl;
}