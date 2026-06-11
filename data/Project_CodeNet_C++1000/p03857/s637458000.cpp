#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

template <int N = 100010>
struct UF{
	int par[N],r[N];
	UF(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		if(r[x] < r[y]){
			par[x] = y;
		}
		else {
			par[y] = x;
			if(r[x] == r[y]){
				r[x] ++;
			}
		}
	}
};

int main(){
	static int n,k,l;
	static int p[100010],q[100010];
	static int r[100010],s[100010];
	scanf("%d%d%d",&n,&k,&l);
	for(int i = 0 ; i < k ; i ++){
		scanf("%d%d",&p[i],&q[i]);
	}
	for(int i = 0 ; i < l ; i ++){
		scanf("%d%d",&r[i],&s[i]);
	}
	
	UF<200010> uf[2];
	for(int i = 0 ; i < k ; i ++){
		uf[0].unit(p[i],q[i]);
	}
	for(int i = 0 ; i < l ; i ++){
		uf[1].unit(r[i],s[i]);
	}
	
	static map<P,int> cnt;
	for(int i = 1 ; i <= n ; i ++){
		cnt[P(uf[0].find(i),uf[1].find(i))] ++;
	}
	for(int i = 1 ; i <= n ; i ++){
		printf("%d%c",cnt[P(uf[0].find(i),uf[1].find(i))],(i==n)?'\n':' ');
	}
}