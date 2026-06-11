#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define lowbit(x) (x&(-x))
inline long long read(){
	long long sum=0,f=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		sum=(sum<<1)+(sum<<3)+(ch^48);
		ch=gc;
	}
	return f*sum;
}
long long a[2000010],t[2000010];
long long n,ans;
inline bool check(long long sum){
	if((a[n-1]<=sum&&a[n]<=sum)||(a[n]<=sum&&a[n+1]<=sum))return 1;
    if((a[n-1]>sum&&a[n]>sum)||(a[n]>sum&&a[n+1]>sum))return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=sum&&a[n+i+1]<=sum)||(a[n-i]<=sum&&a[n-i-1]<=sum))return 1;
        if((a[n+i]>sum&&a[n+i+1]>sum)||(a[n-i]>sum&&a[n-i-1]>sum))return 0;
    }
    return a[1]<=sum;
}
int main(){
	//freopen("pyramid.in","r",stdin);
	//freopen("pyramid.out","w",stdout);
	n=read();
	for(register int i=1;i<=(n<<1)-1;i++)a[i]=read();
	bool fg=0;
	for(register int i=1;i<=(n<<1)-1;i++){
		if(a[i]!=0&&a[i]!=1){
			fg=1;
			break;
		}
	}
	if(fg){
		long long l=1,r=(n<<1)-1;
		while(l<r){
			long long mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		printf("%lld",l);
	}
	else{
		bool ffg=0;
		for(register int i=2;i<=(n<<1)-1;i=-~i){
			if(a[i]==a[i-1]){
				ffg=1;
				break;
			}
		}
		if(ffg){
			for(register int i=n,j=n;i>1&&j<(n<<1)-1;j=-~j,--i){
				if(a[i]==a[i-1]&&a[j]!=a[j+1]){
					printf("%d",a[i]);
					break;
				}
				if(a[i]!=a[i-1]&&a[j]==a[j+1]){
					printf("%d",a[j]);
					break;
				}
				if(a[i]==a[i-1]&&a[j]==a[j+1]&&a[i]==a[j]){
					printf("%d",a[i]);
					break;
				}
			}
		}
		else printf("%d",a[1]);
	}
	return 0;
}