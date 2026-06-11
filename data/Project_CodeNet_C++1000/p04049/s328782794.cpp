/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Os")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
*/

#include <bits/stdc++.h>
//#include <windows.h>

#define ll long long
#define X first
#define Y second
#define MP make_pair

using namespace std;

    /*
const int MAX_MEM = 1e8;
int mpos=0;
char mem[MAX_MEM];
inline void * operator new(size_t n){
	char *res = mem + mpos;
	mpos += n;
	assert(mpos <= MAX_MEM);
	return (void *)res;
}

inline void operator delete(void *){}
    */
const int N = 2e3 + 1;

int n, k, ans[N], t, was, uwas;
vector<int> g[N];

void dfs(int v, int pr=0, int d=0){
	if(k % 2 == 0){
		if(d > k / 2){
			ans[t] += 1;
		}
	}
	else{
		if(d > (k + 1) / 2){
			ans[t] += 1;
		}
		if(d == (k + 1) / 2){
			was += 1;
		}
	}   

	for(int u: g[v]){
		if(pr == u)
			continue;
		dfs(u, v, d + 1);
		if(v == t){
			ans[t] += was;
			if(uwas < was){
				ans[t] += uwas;
				ans[t] -= was;
				uwas = was;	
			}
			was = 0;
		}
	}		
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for(int i = 1;i < n;i++){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}

	for(int i = 1;i <= n;i++){
		t = i, was = 0, uwas = 0;
		dfs(i);
	}

	int res = n;
	for(int i = 1;i <= n;i++)
		res = min(res, ans[i]);//, cout << ans[i] << endl;
	cout << res;
}    
