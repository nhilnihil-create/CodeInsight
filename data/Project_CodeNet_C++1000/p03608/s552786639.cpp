#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007
ll fac[MAX], finv[MAX], inv[MAX];
const int MX = 1000005;
const double PI = acos(-1);

Graph d(200, vector<int>(200, 1000000000));

void warshall_floyd(int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main(){
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    for(int i = 0; i < R; i++){
        cin >> r[i];
        r[i]--;
    }
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        d[a][b] = min(c, d[a][b]);
        d[b][a] = min(c, d[a][b]);
    }
    warshall_floyd(N);
    vector<int> v;
    int ans = 1000000000;
    for(int i = 0; i < R; i++) v.push_back(i);
    do{
        int res = 0;
        for(int i = 1; i < R; i++){
            res += d[r[v[i-1]]][r[v[i]]];
        }
        ans = min(ans, res);
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}