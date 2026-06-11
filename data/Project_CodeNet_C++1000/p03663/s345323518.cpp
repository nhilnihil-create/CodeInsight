#include <bits/stdc++.h>
typedef long long ll;
int qry(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	char s[3];
	scanf("%s",s);
	if (s[0]=='Y') return 1;
	return 0;
}
int main(){
	int w=0;ll L=1;
	for (;qry(L) && w<=9;w++,L*=10);
	if (w>9){
		w=0,L=10;
		for (;!qry(L-1);w++,L*=10);
		printf("! %lld\n",L/10);
		fflush(stdout);
		return 0;
	}
	ll R=L-1,ans=R;
	w--,L/=10;
	while (L<=R){
		ll mid=(L+R)>>1;
		if (qry(mid*10)) ans=std::min(ans,mid),R=mid-1;
		else L=mid+1;
	}
	printf("! %lld\n",ans);
	fflush(stdout);
	return 0;
}