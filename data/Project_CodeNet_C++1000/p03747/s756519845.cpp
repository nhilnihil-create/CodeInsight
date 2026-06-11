#include<bits/stdc++.h>
using namespace std;
int p[100003];
int main(){
	int n,m,i,j,c,t,s=0;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;++i){
		scanf("%d %d",&p[i],&c);
		if(c==1)p[i]+=t;else p[i]-=t;
		s+=p[i]/m,(s-=((p[i]%=m)<0))%=n,(p[i]+=m)%=m;
	}
	sort(p+1,p+n+1),(s+=n)%=n;
	for(i=s+1;i<=n;++i)printf("%d ",p[i]);
	for(i=1;i<=s;++i)printf("%d ",p[i]);
	return 0;
}