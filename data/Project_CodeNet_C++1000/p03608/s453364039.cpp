#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> visit(r);

    rep(i, r){
        cin >> visit[i];
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX_HALF));

    int a,b,c;

    rep(i, m){
        
        cin >> a >> b >> c;

        dist[a][b] = c;
        dist[b][a] = c;
    }

    rep(k, n + 1){
        rep(i, n + 1){
            rep(j, n + 1){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INT_MAX;

    sort(ALL(visit));

    do{

        int tmp = 0;

        for(int i = 1; i < r; i++){
            tmp += dist[visit[i - 1]][visit[i]];
        }

        ans = min(ans, tmp);

    }while(next_permutation(ALL(visit)));

    cout << ans << endl;

    return 0;
}
