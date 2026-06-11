#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){
    
    string a; cin >> a;
    int n = (int)a.size();

    vector<int> al(26);
    rep(i, 26){
        a += 'a' + i;
        al[i] = n + i + 1;
    }

    vector<vector<int>> pl(n + 1, vector<int>(26));
    for(int i = n; i >= 0; i--){
        rep(j, 26)pl[i][j] = al[j];
        if(i == 0)break;
        al[a[i - 1] - 'a'] = i;
    }

    const int inf = 100000000;
    vector<int> prev(n + 27, -1);
    vector<int> dist(n + 27, inf);
    dist[0] = 0;

    queue<int> que;
    que.push(0);
    while(que.size()){
        int v = que.front(); que.pop();
        rep(i, 26){
            int u = pl[v][i];
            if(chmin(dist[u], dist[v] + 1)){
                prev[u] = v;
                if(u <= n)que.push(u);
            }
        }
    }

    string ans = "";
    rep(i, n + 27)ans += 'z';

    int dans = inf;
    rep(i, 26){
        if(dans >= dist[n + i + 1]){
            bool must = dans > dist[n + i + 1];
            dans = dist[n + i + 1];
            string tmp = "";
            for(int t = n + i + 1; t > 0; t = prev[t]){
                tmp += a[t - 1];
            }
            reverse(all(tmp));
            if(must)ans = tmp;
            else chmin<string>(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;

}