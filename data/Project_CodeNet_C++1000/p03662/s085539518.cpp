#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;

#define pb push_back
#define SZ(a) int((a).size())
#define ALL(a) (a).begin(), (a).end()
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) FOR(i,0,n-1)
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

lng power(lng b, lng e) {lng sol=1; while(e>0) {if(e&1) {sol=sol*b;} e>>=1; b*= b;} return sol;}

int N;
vector<int> graph[100010];

vector<int> path;
bool found[100010];

bool dfsPath(int rt, int t) {
    if(found[rt]) return false;
    found[rt] = true;
    path.pb(rt);
    if(rt == t) return true;
    for(int v : graph[rt]) {
        if(dfsPath(v, t)) return true;
    }
    path.pop_back();
    return false;
}

int dfsSol(int rt, int stop) {
    //cout << rt << endl;
    if(rt == stop) return 0;
    if(found[rt]) return 0;
    found[rt] = true;
    int num = 1;
    for(int v : graph[rt]) {
        num += dfsSol(v, stop);
    }
    return num;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N-1) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfsPath(1, N);
    int hf = SZ(path)/2 - 1;
    if(SZ(path)%2 == 1) hf++;
    int u = path[hf];
    int v = path[hf+1];
    //cout << u << " " << v << endl;
    REP(i, 100010) found[i] = 0;
    int sen = dfsSol(1, v);
    //cout << sen << endl;
    REP(i, 100010) found[i] = 0;
    int go = dfsSol(N, u);
    //cout << go << endl;

    if(sen > go) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}
