#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> pi;
typedef long long ll;

const int N = 1000005;

int n , a[N],k,res,h[N];

vector<int> g[N];
void dfs(int u){
	for(auto v : g[u]){
		dfs(v);
		h[u] = max(h[u],1+h[v]);
	}

	if(h[u]==k-1 && u > 1){
		if(a[u] != 1){
			res++;
			h[u] = -1;
		}
	}
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
		if(i == 1 && a[i] != 1)res++,a[i] = 1;
		//cout << a[i] << " " << i << endl;
		if(i>1)g[a[i]].push_back(i);
	}
	dfs(1);

	cout << res << endl;
	return 0;
}
