#include<bits/stdc++.h>
using namespace std;
const long long N=100010;
long long s[N];
int main(){
	long long n,m,last;
	scanf("%d%d",&n,&m);
	scanf("%d",&last);
	long long x,tot=0,fir=last;
	for(long long i=2;i<=n;i++){
		scanf("%d",&x);
		if(x<last){
			tot++;
			s[last+1]-=last;
			s[1]-=last-m;
			s[x+1]+=last-m;
		}else{
			s[last+1]-=last;
			s[x+1]+=last;
		}
		last=x;
	}
	for(long long i=1;i<=m;i++) s[i]+=s[i-1];
	for(long long i=1;i<=m;i++){
		long long k=0;
		if(i<=x) k++;
		if(i<=fir) k--;
		s[i]+=(tot+k)*(i-1);
	}
	long long fav=1;
	for(long long i=2;i<=m;i++) if(s[i]>s[fav]) fav=i;
	printf("%lld\n",x+tot*m-fir-s[fav]);
	return 0;
}
