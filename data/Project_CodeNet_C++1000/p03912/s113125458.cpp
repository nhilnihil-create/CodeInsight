#include<bits/stdc++.h>
using namespace std;
int ans;
int n,m;
int x[100005];
int num[100005],match[100005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,v;i<=n;i++) scanf("%d",&v),x[v%m]++,num[v]++;
	for(int i=1;i<=100000;i++) match[i%m]+=num[i]/2;
	int ans=x[0]/2*2;
	if(m%2==0) ans+=x[m/2]/2*2;
	for(int i=1;i<(m+1)/2;i++){
		int x1=x[i],x2=match[i]*2,y1=x[m-i],y2=match[m-i]*2;
		if(x1<y1) swap(x1,y1),swap(x2,y2);
		ans+=y1*2+min((x1-y1)/2*2,x2);
	}
	cout<<ans/2<<endl;
	return 0;
}