#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

const int MX_N = 1e5+5;

int N, L, T;
int X[MX_N], W[MX_N];

vector<int> dir[2];
int Y[MX_N];

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L >> T;
    FOR(i,0,N-1){
        cin >> X[i] >> W[i];
        Y[i] = ((X[i]+(W[i]==1?T:-T))%L + L)%L;
        dir[W[i]-1].push_back(i);
    }

    sort(Y,Y+N);
    int j = 0;
    if (!dir[0].empty()) {
        int a = dir[0][0], b = X[a];
        for (int c : dir[1]) {
            int d = X[c];
            a += 2*(T/L);
            if (2*(T%L) >= (d-b+L)%L) ++a;
            if (2*(T%L) >= (d-b+L)%L + L) ++a;
            a %= N;
        }
        b = (b+T)%L;
        //cout << a << " AT " << b << endl;

        RFOR(i,N-1,0) if (Y[i] == b) {
            j = (i-a+N)%N;
            break;
        }
    } else {
        int a = dir[1][0], b = ((X[a]-T)%L + L)%L;
        FOR(i,0,N-1) if (Y[i] == b) {
            j = (i-a+N)%N;
            break;
        }
    }
    FOR(i,j,N-1) cout << Y[i] << '\n';
    FOR(i,0,j-1) cout << Y[i] << '\n';
}

