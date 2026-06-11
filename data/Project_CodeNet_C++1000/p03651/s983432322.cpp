#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using pii = pair<int, int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define reps(i,n) for(int i = 1; i <= (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define rreps(i,n) for(int i = (int)(n); i > 0; i--)
#define FOR(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RFOR(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define all(x) (x).begin(), (x).end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = INT_MAX;
const int MOD = 1000000007;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int ngcd(vector<int> a){
    int result;
    result = a[0];
    for(int i = 1; i < a.size() && result != 1; i++) {
        result = gcd(result, a[i]);
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    vi A(N);
    rep(i, N) cin >> A[i];
    int a_max = MAX(A);
    if (K > a_max) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int gcd = ngcd(A);
    if (K % gcd == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}