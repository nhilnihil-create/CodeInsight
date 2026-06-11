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
    ll N;
    cin >> N;
    vector<ll> p(N), b(N);
    rep(i, N) cin >> p[i];

    rep(i, N - 1) cout << 1 + N * i << " ";
    cout << 1 + N * (N - 1) << endl;

    ll li = N * (N - 1) + 1;

    rep(i, N) {
        b[p[i] - 1] = (li + i + 1) - (1 + N * (p[i] - 1));
    }

    rep(i, N - 1) cout << b[i] << " ";
    cout << b[N - 1] << endl; 
    return 0;
}