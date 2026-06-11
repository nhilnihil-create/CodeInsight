#include<bits/stdc++.h>
#define N 300005
using namespace std;
int val[N];
int n,m;
void solve(int l,int r){
	val[1]++;val[r-l+1]--;
	for(int i=1,ne,lastl=1e9;i<=r;i=ne+1){
		if(i<=l) ne=min(l/(l/i),r/(r/i));
		else ne=r;
		if(l/i<lastl){
			if(l/i>=r-l){
				val[l/i+1]++,val[min(lastl,r/i)+1]--;
			}else{
				val[r-l+1]++,val[min(lastl,r/i)+1]--;
				return;
			}
			lastl=l/i;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,l,r;i<=n;i++){
		scanf("%d%d",&l,&r);
		solve(l-1,r);
	}
	for(int i=1;i<=m;i++) printf("%d\n",val[i]+=val[i-1]);
	return 0;
}