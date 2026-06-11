#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,l,t,x,w,ans[100001],p,s;
int main(){
	scanf("%d%d%d",&n,&l,&t);
	for(long long i=1;i<=n;i++){
		scanf("%d%d",&x,&w);
        if(w==2)p=x-t;
        else p=x+t;
        if(p>0)s=(s+p/l)%n;
        if(p<0)s=(s+(p+1)/l-1)%n;
        ans[i]=(p%l+l)%l;
    }
    sort(ans+1,ans+n+1);
    if(s>=0)s=s%n;
    else{
    	p=(s+1)/n+1;
    	s=s+p*n;
	}
    for(long long i=s+1;i<=n;i++)printf("%d\n",ans[i]);
    for(long long i=1;i<=s;i++)printf("%d\n",ans[i]);
}