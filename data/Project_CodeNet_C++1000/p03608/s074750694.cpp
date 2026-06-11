#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    for (int i = 0; i < R; i++) {
        cin >> r[i]; r[i]--;
    }
    vector<vector<int>> G(N, vector<int> (N, inINF));
    for (int i = 0; i < N; i++) {
        G[i][i] = 0;
    }
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c; a--; b--;
        G[a][b] = c;
        G[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(G[i][k] == inINF || G[k][j] == inINF) continue;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    vector<int> v(R);
    for (int i = 0; i < R; i++) {
        v[i] = i;
    }
    int ans = inINF;
    do{
        int tmp = 0;
        for (int i = 0; i < R-1; i++) {
            tmp += G[r[v[i]]][r[v[i+1]]];
        }
        ans = min(ans, tmp);
    }while(next_permutation(ALL(v)));

    printf("%d\n", ans);

}   