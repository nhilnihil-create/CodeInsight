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
const int INF   = 1e9;
const ll  INFLL = 1e18;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};

const int MAX_N = 1e5 + 1;

int main()
{
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    ll ans = 0;
    rep(i, N) {
        if (!(~K & A[i])) ans += B[i];
    }

    for (int b=30; b>=0; b--) {
        ll tmp = 0;
        rep(i, N) {
            if (!(K>>b&1) || A[i]>>b&1) continue;
            bool ok = true;
            for (int j=30; j>b; j--) {
                if (A[i]>>j & ~K>>j) {
                    ok = false;
                    break;
                }
            }
            if (ok) tmp += B[i];
        }
        ans = max(ans, tmp);
#ifdef DEBUG
        DUMP(b);
        DUMP(tmp);
#endif
    }
    cout << ans << endl;
}