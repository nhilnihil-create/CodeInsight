#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 2005
#define MOD 99994711
#define ba 47
//define ivorysi
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
int N,M;
int a[105];
vector<int> v,ans[2];
void Solve() {
    read(N);read(M);
    for(int i = 1 ; i <= M ; ++i) read(a[i]);
    for(int i = 1 ; i <= M ; ++i) {
	if(a[i] & 1) v.pb(a[i]);
    }
    if(v.size() > 2) {puts("Impossible");return;}
    if(v.size()) {
	int t = v.back();
	ans[0].pb(t);
	v.pop_back();
    }
    for(int i = 1 ; i <= M ; ++i) {
	if(a[i] % 2 == 0) {
	    ans[0].pb(a[i]);
	}
    }
    if(v.size()) {
	int t = v.back();
	ans[0].pb(t);
	v.pop_back();
    }
    
    for(int i = 0 ; i < ans[0].size() ; ++i) {
	if(i == 0) {
	    if(ans[0][i] != 1) ans[1].pb(ans[0][i] - 1);
	}
	else if(i == ans[0].size() - 1){
	    ans[1].pb(ans[0][i] + 1);
	}
	else ans[1].pb(ans[0][i]);
    }
    if(ans[0].size() == 1) ans[1].pb(1);
    for(auto t : ans[0]) {
	out(t);space;
	
    }
    enter;
    out(ans[1].size());enter;
    for(auto t : ans[1]) {
	out(t);space;
    }
    enter;
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
