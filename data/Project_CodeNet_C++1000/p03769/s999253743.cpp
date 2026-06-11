#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 100005
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
vector<int> p;
int64 N;
void Solve() {
    read(N);
    int num = 0,t;
    ++N;
    for(int i = 40 ; i >= 0 ; --i) {
	if((N >> i) & 1) {
	    t = i;
	    break;
	}
    }
    for(int i = t - 1 ; i >= 0 ; --i) {
	++num;
	p.pb(num);
	if((N >> i) & 1) {
	    ++num;
	    p.insert(p.begin(),num);
	}
    }
    t = p.size();
    for(int i = 1 ; i <= t ; ++i) p.pb(i);
    out(p.size());enter;
    for(auto a : p) {
	out(a);space;
    }
    enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
