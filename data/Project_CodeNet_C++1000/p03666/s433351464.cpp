#include <bits/stdc++.h>
using namespace std;
using LL = long long; using PII = pair<LL, LL>; using VI = vector<LL>; using VVI = vector<VI>;
using VB = vector<bool>; using VS = vector<string>; using VP = vector<PII>;
#define VV(T)        vector<vector<T>>
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define $(x)         {cout << #x << " = " << (x) << endl;}

const string YES = "YES";
const string NO = "NO";

void solve(LL N, LL A, LL B, LL C, LL D){
    LL X = abs(A - B);
    LL l = -(N - 1) * D, u = -(N - 1) * C;
    if (l <= X && X <= u) {
        cout << YES << endl;
        return;
    }
    REP(i, N - 1) {
        l += C + D;
        u += C + D;
        if (l <= X && X <= u) {
            cout << YES << endl;
            return;
        }
    }
    cout << NO << endl;
}

int main(){
    LL N;
    scanf("%lld",&N);
    LL A;
    scanf("%lld",&A);
    LL B;
    scanf("%lld",&B);
    LL C;
    scanf("%lld",&C);
    LL D;
    scanf("%lld",&D);
    solve(N, A, B, C, D);
    return 0;
}
