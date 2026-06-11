#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int sum[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		sum[l]++; sum[r+1]--; l--;
		for(int j=1,nxt;j<=l;j=nxt+1){
			nxt=min(l/(l/j),r/(r/j));
			if(l/j<r/j) sum[j]++,sum[nxt+1]--;
		}
	}
	for(int i=1;i<=m;++i){
		sum[i]+=sum[i-1];
		printf("%d\n",sum[i]);
	}
	return 0;
}