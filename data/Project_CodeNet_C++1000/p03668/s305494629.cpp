#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 200005

using namespace std;

int n;
int h[N], adj[N], nxt[N], o;

inline void add (int u, int v) {
	nxt[++o] = h[u];
	h[u] = o;
	adj[o] = v;
	return ;
}

int dfs (int u, int la) {
    int sum = 0;
    for (int i = h[u]; i; i = nxt[i]) {
    	int v = adj[i];
    	if (la != v)
    		sum ^= dfs (v, u) + 1; 
    }
    return sum;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
        scanf ("%d%d", &u, &v);
        add (u, v);
        add (v, u); 
    }
    if (dfs (1, 0))
    	puts ("Alice");
    else 
    	puts ("Bob");
    return 0;
}