#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N), c(M), d(M);

    rep(i, N) cin >> a[i] >> b[i];
    rep(i, M) cin >> c[i] >> d[i];

    rep(i, N) {
        int min = 1e9;
        int index;
        rep(j, M) {
            int dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (dis < min) {
                min = dis;
                index = j;
            }
        }

        cout << index + 1 << endl;
    }
    return 0;
}