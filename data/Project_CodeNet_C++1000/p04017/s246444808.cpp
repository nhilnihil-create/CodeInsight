#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int rmq[18][N];
int n, L, Q;
int a[N];
void init(){
	int cur = 1;
	for(int i = 1; i <= n; i++){
		if(cur < i) cur = i;
		for(; cur <= n && a[cur] <= L + a[i]; cur++);
		rmq[0][i] = cur - 1;
	}
	for(int i = 1; i < 18; i++)
		for(int j = 1; j <= n; j++)
			rmq[i][j] = rmq[i - 1][rmq[i - 1][j]];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> L >> Q;
	init();
	while(Q--){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		int ans = 0;
		for(int i = 17; i >= 0; i--){
			int na = rmq[i][a];
			if(na < b){
				a = na;
				ans += (1 << i);
			}
		}
		cout << ans + 1 << "\n";
	}
	return 0;
}
