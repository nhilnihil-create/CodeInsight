#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(2e5) + 2;
const int inf = (int)1e15;

int n, r, s, u, v, m, k;

int lab1[N], mask[N], cnt;
int Find1(int u) {return lab1[u] < 0? u: lab1[u] = Find1(lab1[u]);}
void Union1(int r, int s) {
    if(lab1[r] > lab1[s]) swap(r, s);
    lab1[r] += lab1[s], lab1[s] = r;
}

struct TLab{
    unordered_map<int, int> mmap;
    int lab;
} lab[N];
int Find(int u) {return lab[u].lab < 0? u: lab[u].lab = Find(lab[u].lab);}
void Union(int r, int s) {
    if(lab[r].lab > lab[s].lab) swap(r, s);
    lab[r].lab += lab[s].lab, lab[s].lab = r;
    for(auto p: lab[s].mmap) lab[r].mmap[p.fi] += p.se;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> k;
    memset(&lab1, -1, sizeof lab1);
    while(m --) {
        cin >> u >> v;
        r = Find1(u), s = Find1(v);
        if(r != s) Union1(r, s);
    }
    for(int i = 1; i <= n; ++i) if(lab1[i] < 0) mask[i] = ++cnt;
    for(int i = 1; i <= n; ++i) {
        if(lab1[i] > 0) mask[i] = mask[Find1(i)];
        lab[i].lab = -1;
        ++lab[i].mmap[mask[i]];
    }
    while(k --) {
        cin >> u >> v;
        r = Find(u), s = Find(v);
        if(r != s) Union(r, s);
    }
    for(int i = 1; i <= n; ++i) cout << lab[Find(i)].mmap[mask[i]] << ' ';
}
