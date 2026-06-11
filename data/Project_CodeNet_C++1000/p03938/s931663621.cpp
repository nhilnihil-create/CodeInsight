#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void _main()
{
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, 0, N) cin >> p[i];
    vector<int> r(N);
    rep(i, 0, N) r[p[i] - 1] = i + 1;
    vector<int> A(N), B(N);
    rep(i, 0, N)
    {
        A[i] = 30000 * (i + 1);
        B[i] = 30000 * (N - (i + 1)) + r[i];
    }
    rep(i, 0, N)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    rep(i, 0, N)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}
