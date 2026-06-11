#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
bool pos[N];
int cnt[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		pos[i] = false;
		cnt[i] = 1;
	}
	pos[1] = true;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin>>x>>y;
		if(pos[x]){
			if(cnt[x] == 1)pos[x] = false;
			pos[y] = true;
		}
		cnt[x]--;
		cnt[y]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(pos[i])ans++;
	}
	cout<<ans<<endl;

	return 0;
}