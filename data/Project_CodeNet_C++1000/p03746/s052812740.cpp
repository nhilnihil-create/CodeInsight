#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
signed main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> Graph[N];
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    vector<bool> Judge(N, false);
    vector<int> End0, End1;
    End0.push_back(0);
    Judge[0] = true;
    int now = 0;
    while(true) {
        bool judge = true;
        for(auto x : Graph[now]) {
            if(Judge[x]) continue;
            judge = false;
            now = x;
            Judge[now] = true;
            End0.push_back(x);
            break;
        }
        if(judge) break;
    }
    now = 0;
    while(true) {
        bool judge = true;
        for(auto x : Graph[now]) {
            if(Judge[x]) continue;
            judge = false;
            now = x;
            Judge[now] = true;
            End1.push_back(x);
            break;
        }
        if(judge) break;
    }
    reverse(all(End1));
    int s0 = End0.size(), s1 = End1.size();
    cout << s0 + s1 << endl;
    for(auto x : End1) cout << x + 1 << ' ';
    for(auto x : End0) cout << x + 1 << ' ';
}
