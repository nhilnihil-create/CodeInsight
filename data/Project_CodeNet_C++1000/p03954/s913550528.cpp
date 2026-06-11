#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010],c[200010];
int ans;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}

bool check(int x){
	int minv=2*1e5;
	for(int i=1;i<2*n;i++){
		if(a[i]>=x) c[i]=1;
		else c[i]=0;
	}
	bool flag=bool(c[1]);
	for(int i=2;i<=n;i++){
		if(c[i]==c[i-1]) {
			if(minv>n-i) {
				minv=n-i;
				flag=bool(c[i]);
			}
		}
	}
	for(int i=n;i<2*n-1;i++){
		if(c[i]==c[i+1]) {
			if(minv>i-n) {
				minv=i-n;
				flag=bool(c[i]);
			}
		}
	}
	return flag;
}

int main(){
	
	n=read();
	for(int i=1;i<2*n;i++){
		a[i]=read();
	}
	int l=1,r=2*n;
	while(l<r){
		int mid=(l+r)>>1;
//		cout<<mid<<' ';
		if(check(mid)){
			ans=mid;
			l=mid+1;
//			cout<<"true"<<' ';
		}
		else {
			r=mid;
//			cout<<"false"<<' ';
		}
//		cout<<endl;
	}
	printf("%d\n",ans);
	return 0;
}