#include<bits/stdc++.h>
using namespace std;
int n,a[200010],l=0,r=2e9,mid,b[200010],ans;

void get_b(){
	for(int i=1;i<=2*n-1;i++){
		if(a[i]>mid) b[i]=1;
		else b[i]=0;
	}
}

int work(){
	if(b[n]==b[n-1]||b[n]==b[n+1]) return b[n];
	int g=n-1,f=n+1;
	while(g){
		if(b[g]==b[g-1]) break;
		g--;
	}
	while(f<=2*n-1){
		if(b[f]==b[f+1]) break;
		f++;
	}
	if(g==0&&f==2*n){
		if(n&1) return b[n];
		else return b[n]^1;
	}
	if(f-n<n-g)	return b[f];
	else return b[g];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
	b[0]=-1;
	while(l<=r){
		mid=(l+r)/2;
		get_b();
		if(work()==0) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	
	return 0;
}