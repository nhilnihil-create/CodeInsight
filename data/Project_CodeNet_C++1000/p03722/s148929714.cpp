#include <bits/stdc++.h>
using namespace std;

// macro-----------------------------------------------------------------------------------------
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
const int inf = 100100100100000;
const int mod = 1000000007;

// general_method--------------------------------------------------------------------------------
vector<int> cs(vector<int> arr) {
    vector<int> ret = arr;
    rep(i, 1, arr.size()) { ret[i] += ret[i - 1]; }
    return ret;
}

// io_method-------------------------------------------------------------------------------------
int input() {
    int tmp;
    cin >> tmp;
    return tmp;
}
string raw_input() {
    string tmp;
    cin >> tmp;
    return tmp;
}
void print(int n) { cout << n << endl; }
void print(vector<int> arr) {
    cout << arr[0];
    rep(i, 1, arr.size()) cout << " " << arr[i];
    cout << endl;
}
void print(string s) { cout << s << endl; }

// main_method-----------------------------------------------------------------------------------

struct edge {
    int from, to, cost;
};
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a - 1, b - 1, -c};
    }

    bool isnc = false;
    vector<int> dist(n, inf);
    dist[0] = 0;

    rep(i, 0, n) {
        rep(j, 0, m) {
            int frm = edges[j].from, to = edges[j].to, cost = edges[j].cost;
            if (dist[frm] != inf && dist[to] > dist[frm] + cost) {
                dist[to] = dist[frm] + cost;
                if (i == n - 1 && to == n - 1)
                    isnc = true;
            }
        }
    }

    if (isnc)
        print("inf");
    else
        print(-dist.back());
}
