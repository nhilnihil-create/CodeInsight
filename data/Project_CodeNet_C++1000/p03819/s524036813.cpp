#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
int fen[maxn], ans[maxn], qtd[maxn];
vector<int> divs[maxn], bck[maxn];
void add(int x, int v){
	for(; x < maxn; x += x & - x) fen[x] += v;
}
int sum(int x){
	int ans = 0;
	for(; x; x -= x & - x) ans += fen[x];
	return ans;
}
int main(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++) for(int j = i; j <= m; j += i) divs[j].push_back(i);
	for(int i = 1; i <= n; i++){
		int l, r; cin >> l >> r;
		qtd[r]++;
		bck[l].push_back(r);
	}
	for(int i = m; i >= 1; i--){
		add(i, qtd[i]);
		for(int q: divs[i]) ans[q] += sum(i + q - 1);
		for(int q: bck[i]) add(q, -1);
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}
