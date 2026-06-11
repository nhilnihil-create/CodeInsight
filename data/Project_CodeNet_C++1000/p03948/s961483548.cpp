#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 200005;

int n, a[MAXN];

int main(){
	int t;
	scanf("%d %d",&n,&t);
	t  = 1;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	int dap = 0, minv = 2e9;
	for(int i=1; i<=n; i++){
		dap = max(dap, a[i] - minv);
		minv = min(minv, a[i]);
	}
	minv = 2e9;
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(a[i] - minv == dap) cnt++;
		minv = min(minv, a[i]);
	}
	cout << max(1, cnt - t + 1);
}
