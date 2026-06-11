#include<bits/stdc++.h>
using namespace std;
int n,f[100005],a[100005],L,s;
int q,p[100005][50];
int power(int a,int k){
	if(k == 0) return 1;
	if(k == 1) return a;
	int t = power(a,k >> 1);
	if(k % 2) return t * t * a;
	else return t * t;
}
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)scanf("%d",&a[i]);
	scanf("%d",&L);
	for(int i = 1,step = 1; i <= n; i++){
		while(a[i] - a[step] > L)step++;
		p[i][0] = step;
	}
	for(int i = 1,j = 2; j <= n; i++,j *= 2,s++){
		for(int k = 1; k <= n; k++){
			p[k][i] = p[p[k][i - 1]][i - 1];
		}
	}
	scanf("%d",&q);
	int x,y,j,k,ans;
	for(int i = 1; i <= q; i++){
		scanf("%d%d",&x,&y);
		if(x > y) swap(x,y);
		ans = 1;
		k = y;
		for(int j = s; j >= 0; j--){
			if(p[k][j] > x){
				k = p[k][j];
				ans += power(2,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}