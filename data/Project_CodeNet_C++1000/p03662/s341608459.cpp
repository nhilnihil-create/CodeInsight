#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)

typedef long long ll;
typedef pair<ll, ll> llP;
typedef pair<int, int> intP;
typedef std::priority_queue<int> IntPrioQueue; //Z->A
typedef std::priority_queue<int, std::vector<int>, std::greater<int> > IntReversePrioQueue; //A->Z

const int MAX = 100010;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const int MOD = 1000000007;

vector <int> adj[MAX];
int disb[MAX], disw[MAX];

void dfs(int p, int* dis, int q) {
    for (auto nex : adj[p]) {
        if (dis[nex] == INF && nex != q) {
            dis[nex] = dis[p] + 1;
            dfs(nex, dis, q);
        }
    }
    return;
}

void solve(void){
    int N;
    cin >> N;
    rep(N-1, i) {
        int a, b;
        scanf("%d %d\n", &a, &b);
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    rep(N, i) {
        disb[i] = disw[i] = INF;
    }
    disb[0] = disw[N-1] = 0;
    dfs(0, disb, N-1);
    dfs(N-1, disw, 0);
    int cnt = 0;
    rep(N, i) {
        if (disb[i] <= disw[i]) cnt++;
        else cnt--;
    }
    cout << (cnt>0?"Fennec":"Snuke") << endl;
}

int main(void){
  solve();
  return 0;
}
