#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pdi pair<db,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define eps 1e-8
#define mo 974711
#define MAXN 200005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
	if(c == '-') f = -1;
	c = getchar();
    }
    while(c >= '0' && c <= '9') {
	res = res * 10 + c - '0';
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
int a[305][305],ans;
int cnt[305],pos[305];
bool vis[305];
void Solve() {
    read(N);read(M);
    for(int i = 1 ; i <= N ; ++i) {
	for(int j = 1 ; j <= M ; ++j) {
	    read(a[i][j]);
	}
    }
    for(int i = 1 ; i <= N ; ++i) {cnt[a[i][1]]++;pos[i] = 1;}
    for(int i = 1 ; i <= M ; ++i) ans = max(ans,cnt[i]);
    for(int k = 1 ; k < M ; ++k) {
	int t = 1;
	for(int j = 1 ; j <= M ; ++j) {
	    if(cnt[j] > cnt[t]) t = j;
	}
	vis[t] = 1;
	for(int i = 1 ; i <= N ; ++i) {
	    cnt[a[i][pos[i]]]--;
	    while(vis[a[i][pos[i]]]) {++pos[i];}
	    cnt[a[i][pos[i]]]++;
	}
	int tmp = 0;
	for(int j = 1 ; j <= M ; ++j) {
	    tmp = max(tmp,cnt[j]);
	}
	ans = min(ans,tmp);
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
