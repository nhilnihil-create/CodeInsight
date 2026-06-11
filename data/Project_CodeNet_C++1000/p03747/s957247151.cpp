//Ants on a Circle
//CodeForces_652F
//18.10.03
#include<cstdio>
#include<iostream>
#include<algorithm>

const int MAXN=100000+10;

int Read(){
	char ch;
	while((ch=getchar())<48||57<ch);
	int ans=ch-48;
	while(48<=(ch=getchar())&&ch<=57)
		ans=(ans<<3)+(ans<<1)+ch-48;
	return ans;
}

int x[MAXN];
int w[MAXN];

int main(){
#ifdef EagleBear
	freopen("Ants on a Circle.in","r",stdin);
//	freopen("Ants on a Circle.out","w",stdout);
#endif

	int n=Read();
	int l=Read();
	int t=Read();
	for(int i=1;i<=n;++i)
		x[i]=Read(),w[i]=Read();
	
	int cross_cnt=0;
	for(int i=1;i<=n;++i)
		w[i]==1?x[i]+=t:x[i]-=t;
		
	for(int i=1;i<=n;++i){
		cross_cnt+=x[i]>=0?x[i]/l:(x[i]+1)/l-1;
		x[i]=(x[i]%l+l)%l;
	}
	
//	std::cout<<"cross_cnt="<<cross_cnt<<std::endl;
	std::sort(x+1,x+n+1);
	for(int i=1;i<=n;++i){
		int k=(i+cross_cnt%n+n)%n;
		if(k==0) k=n;
		printf("%d\n",x[k]);
	}
	
	return 0;
}

