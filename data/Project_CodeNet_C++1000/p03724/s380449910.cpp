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
    vector<int> ab(N, 0);

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ab[a]++;
        ab[b]++;
    }

    bool flag = true;
    rep(i, N) {
        if (ab[i] % 2) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}