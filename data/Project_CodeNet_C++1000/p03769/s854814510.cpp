#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2010;
ll n;
int ans[maxn], cnt, a[maxn];

vector<int> g;

int main(){

	scanf("%lld", &n);
	int tot=0;
	for(int i=50;i>=0;i--){
		if((1ll<<i)-1<=n){ tot=i; break; }
	}
	// printf("%lld\n", 1ll<<tot);
	n-=(1ll<<tot)-1;
	for(int i=1;i<=tot;i++) g.push_back(i);
	int m=tot;
	// printf("n = %lld\n", n);
	for(int i=(tot-1);i>=0;i--){
		if(!(n & (1ll<<i))) continue;
		m++;
		// g.insert(m,g.begin()+i);
		g.insert(g.begin()+i, m);
	}
	for(int i=1;i<=m;i++) g.push_back(i);
	printf("%d\n", 2*m);
	for(int i=0;i<m*2;i++) printf("%d ", g[i]);
	return 0;
}