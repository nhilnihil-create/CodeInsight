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
const long long MOD = 1e9 + 7;
int main()
{
    ll N;
    cin >> N;
    vector<ll> T(N), A(N), Ti(N), Ai(N);
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> A[i];

    Ti[0] = -1; Ai[N - 1] = -1;
    repd(i, 1, N) {
        if (T[i - 1] < T[i]) {
            Ti[i] = -1;
        }
        else {
            Ti[i] = T[i];
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        if (A[i + 1] < A[i]) {
            Ai[i] = -1;
        }
        else {
            Ai[i] = A[i];
        }
    }
/*
    rep(i, N) {
        cout << Ti[i] << " " << Ai[i] << endl;
    }
*/
    ll cnt = 1;
    bool flag = true;
    rep(i, N) {
        if (Ti[i] == -1 && Ai[i] == -1) {
            if (A[i] != T[i]) flag = false;
        }
        else {
            if (Ti[i] == -1) {
                if (T[i] > A[i]) flag = false;
            }
            else if (Ai[i] == -1) {
                if (A[i] > T[i]) flag = false;
            }
            else if (Ti[i] != -1 && Ai[i] != -1) {
                cnt *= min(Ti[i], Ai[i]);
            }
        }
        cnt %= MOD;
    }

    cout << (flag ? cnt : 0) << endl;
    return 0;
}