#include <bits/stdc++.h>

using namespace std;

vector <int> V[101010];
int L[101010], R[101010], D[101010];
int T[303030];
int P[101010][22];
int n,k,ans,cnt,sz;

int dfs(int p)
{
	int i,t;
	
	L[p] = R[p] = cnt++;
	
	for(i=0;i<V[p].size();i++){
		t = V[p][i];
		P[t][0] = p;
		D[t] = D[p] + 1;
		R[p] = max(R[p], dfs(t));
	}
	
	return R[p];
}

void update(int p, int s, int e, int l, int r)
{
	if(r < s || e < l) return;
	if(l <= s && e <= r){
		T[p] = 0;
		return;
	}
	
	update(p<<1, s, s+e>>1, l, r);
	update(p<<1|1, (s+e>>1)+1, e, l, r);
	
	if(D[T[p<<1]] > D[T[p<<1|1]]) T[p] = T[p<<1];
	else T[p] = T[p<<1|1];
}

int par(int p, int t)
{
	int i;
	
	for(i=0;i<=18;i++){
		if(t & (1<<i)) p = P[p][i];
	}
	
	return p;
}

int main()
{
	int i,j,a,p;
	
	scanf("%d%d", &n,&k);
	
	scanf("%d", &a);
	if(a != 1) ans ++;
	
	for(i=2;i<=n;i++){
		scanf("%d",&a);
		V[a].push_back(i);
	}
	
	dfs(1);
	D[0] = -1;
	
	for(i=1;i<=18;i++){
		for(j=1;j<=n;j++){
			P[j][i] = P[P[j][i-1]][i-1];
		}
	}
	
	for(sz=1;sz<n;sz<<=1);
	
	for(i=1;i<=n;i++){
		T[sz + L[i]] = i;
	}
	
	for(i=sz-1;i;i--){
		if(D[T[i<<1]] > D[T[i<<1|1]]) T[i] = T[i<<1];
		else T[i] = T[i<<1|1];
	}
	
	for(;;ans++){
		p = T[1];
		if(D[p] <= k) break;
		p = par(p, k-1);
		update(1, 0, sz-1, L[p], R[p]);
		
		//printf("%d %d\n",L[p],R[p]);
		//for(i=1;i<sz+sz;i++) printf("%d ",T[i]);
		//printf("\n");
	}
	
	printf("%d\n",ans);
	
	return 0;
}