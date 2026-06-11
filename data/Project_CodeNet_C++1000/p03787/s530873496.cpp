#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


vector<int> e[N];
int color[N];
int n, m;
bool flag;

void dfs(int v, int c) {
    color[v] = c;
    for (auto u: e[v]) {
        if (color[u] == -1) {
            dfs(u, c ^ 1);
        }
        if (color[u] != (c ^ 1))
            flag = 1;
    }
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    int even = 0; 
    int odd = 0;
    memset(color, -1, sizeof(color));
    int one = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (e[i].empty()) {
                one++;
            }
            else {
                flag = 0;
                dfs(i, 0);
                if (flag)
                    odd++;
                else
                    even++;
            }
        }
    }
    db3(odd, even, one);
    ll answer = odd + even * 2; 
    answer += odd * 1ll * even * 2;
    answer += odd * 1ll * (odd - 1);
    answer += even * 1ll * (even - 1) * 2;
    //db(answer);
    answer += one * 1ll * one;
    answer += one * 1ll * (n - one) * 2;
    cout << answer << endl;


    return 0;
}

