
#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

ll d[102][102];
int V;

void warshall_floyd() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}

int main() {
    int N, M;
    ll edge[102][102];
    cin >> N >> M;
    V = N;
    rep(i, N) {
        rep(j, N) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = 100000000000;
            }

            edge[i][j] = -1;
        }
    }



    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cin >> d[a][b];
        edge[a][b] = d[a][b];
        d[b][a] = d[a][b];
        edge[b][a] = d[b][a];

    }

    warshall_floyd();
    int ans = 0;
    rep(i, N) {
        rep(j, N) {
//            cout << d[i][j] << endl;
            if (edge[i][j] != -1 && edge[i][j] != d[i][j]) {
                ans++;
            }
        }
    }

    cout << ans/2 << endl;
}