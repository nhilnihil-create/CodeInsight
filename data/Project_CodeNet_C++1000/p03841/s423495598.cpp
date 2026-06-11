#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 505
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
    	if(c == '-') f = -1;
    	c = getchar();
    }
    while(c >= '0' && c <= '9') {
    	res = res * 10 +c - '0';
    	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
	out(x / 10);
    }
    putchar('0' + x % 10);
}
int N;
int x[MAXN],id[MAXN];
int val[MAXN * MAXN];
bool vis[MAXN];
vector<int> r;
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {
        read(x[i]);
        val[x[i]] = i;
        id[i] = i;
    }
    sort(id + 1,id + N + 1,[](int a,int b){return x[a] < x[b];});
    int p = 1,rem = id[1] - 1;
    vis[1] = 1;
    for(int i = 1 ; i <= N * N ; ++i) {
        if(val[i]) {
            if(!vis[val[i]]) {puts("No");return;}
            for(int j = 1 ; j <= N - val[i] ; ++j) r.pb(val[i]);
        }
        else {
            while(!rem && p < N) {++p;rem = id[p] - 1;}
            if(rem) {
                val[i] = id[p];
                --rem;
                if(!rem) vis[id[p]] = 1;
            }
            else {
                if(r.size() == 0) {puts("No");return;}
                val[i] = r.back();r.pop_back();
            }
        }
    }
    puts("Yes");
    for(int i = 1 ; i <= N * N ; ++i) {out(val[i]);space;}
    enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
