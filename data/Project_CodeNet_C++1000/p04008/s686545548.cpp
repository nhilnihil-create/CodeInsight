#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
const int mx = 100000;

int N, K;
int ans = 0;
vector<int> G[mx];

int dfs(int v, int d){
    int res = (d > K ? 1 : -mx);
    for(int u : G[v])chmax(res, dfs(u, d + 1) + 1);
    if(res == K){ ans++; return -mx; }
    else return res;
}

int main(){

    cin >> N >> K;
    rep(i, N){
        int a;
        cin >> a;
        a--;
        if(i == 0){
            if(a != 0)ans++;
            continue;
        }
        G[a].push_back(i);
    }

    dfs(0, 0);
    cout << ans << endl;

}