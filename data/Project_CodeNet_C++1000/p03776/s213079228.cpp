#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long
#define MOD 1e9+7
#define MAX_V
const double PI=3.14159265358979323846;

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain; 

//Combination Table
ll C[51][51]; /* C[n][k] -> nCk */

void comb_table(int N) {
    REP(i, N+1) REP(j, i+1) {
        if(j == 0 || j == i) {
            C[i][j] = 1LL;
        } else {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]);
        }
    }
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    REP(i, n) cin >> v[i];

    comb_table(n);

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    double ans1 = 0;
    ll ans2 = 0;

    REP(i, a) {
        ans1 += v[i];
    }
    ans1 /= a;

    int n_num = 0, a_num = 0; 

    /* n個のなかからv[a-1]となるものの個数を調べる */
    REP(i, n) {
        if(v[i] == v[a-1]) n_num++;
    }

    /* a個のなかからv[a-1]となるものの個数を調べる */
    REP(i, a) {
        if(v[i] == v[a-1]) a_num++;
    }

    //cout << a_num << " " << n_num << endl;

    if(v[0] != v[a-1]) {
        cout << ans1 << endl << C[n_num][a_num] << endl;
    } else {
        ll ans_2 = 0;
        REPN(i, a_num, min(b, n_num)+1) {
            ans_2 += C[n_num][i];
        }
        cout << ans1 << endl << ans_2 << endl;
    }

    
    return 0;
}