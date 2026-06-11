#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M), c(M);
    vector<vector<int>> d(N, vector<int> (N, inINF));

    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        d[a[i]][b[i]] = c[i];
        d[b[i]][a[i]] = c[i];
    }
    for (int i = 0; i < N; i++) {
        d[i][i] = 0;
    }
    

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }   
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if(d[a[i]][b[i]] < c[i]){
            ans++;
        }
    }
    printf("%d\n", ans);



}