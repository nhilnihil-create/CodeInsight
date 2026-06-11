#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;


int main(){
    int n, m, R;
    cin >> n >> m >> R;
    int r[10];
    rep(i, R){
        cin >> r[i];
        r[i]--;
    }
    int d[200][200];
    rep(i, 200) fill(d[i], d[i] + 200, INF);
    vector<int> vec[200];
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        vec[a].push_back(a);
        vec[b].push_back(b);
        d[a][b] = c;
        d[b][a] = c;
        d[a][a] = 0;
        d[b][b] = 0;
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    vector<int> route;
    for(int i = 0; i < R; i++){
        route.push_back(i);
    }
    int ans = INF;
    do{
        int tmp = 0;
        for(int i = 0; i < R-1; i++){
            tmp += d[r[route[i]]][r[route[i+1]]];
        }
        ans = min(tmp, ans);

    } while(next_permutation(all(route)));
    cout << ans << endl;

}