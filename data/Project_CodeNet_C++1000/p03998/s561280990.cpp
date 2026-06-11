#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

char solver(string &x) {
    char nextturn = x[0];
    reverse(ALL(x));
    x.pop_back();
    reverse(ALL(x));
    return nextturn;
}

char solve(string &A, string &B, string &C) {
    char nowturn = 'a';
    while (true) {
        if (nowturn == 'a') {
            if (len(A) == 0) return 'A';
            nowturn = solver(A);
        } else if (nowturn == 'b') {
            if (len(B) == 0) return 'B';
            nowturn = solver(B);
        } else {
            if (len(C) == 0) return 'C';
            nowturn = solver(C);
        }
    }
}

int main() {
    string A, B, C; cin >> A >> B >> C;
    cout << solve(A, B, C) << endl;
}