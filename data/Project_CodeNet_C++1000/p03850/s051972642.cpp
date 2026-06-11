#include<bits/stdc++.h>
using namespace std;
long long a[100005],sum[100005],sum2[100005];
char c[100005];
set<int> minu;
long long getsum(int l,int r){
	if(l>r) return 0;
	return (sum[r]-((l==0)?0:sum[l-1]));
}
long long getsum2(int l,int r){
	if(l>r) return 0;
	return (sum2[r]-((l==0)?0:sum2[l-1]));
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%I64d",&a[0]);
	c[0]='+';
	for(int i=1;i<n;i++){
		string tmp;
	//	scanf("%c",&c[i]);
		cin>>tmp;
		c[i]=tmp[0];
		scanf("%I64d",&a[i]);
		if(c[i]=='-') minu.insert(i);
	}
	sum[0]=a[0];
	sum2[0]=a[0];
	for(int i=1;i<n;i++){
		sum[i]=a[i]+sum[i-1];
		if(c[i]=='+') sum2[i]=sum2[i-1]+a[i]; else sum2[i]=sum2[i-1]-a[i];
	}
//	for(int i=0;i<n;i++) cout<<sum2[i]<<" ";
//	cout<<endl;
	long long now=0,ma=getsum2(0,n-1);
	for(int i=0;i<n;i++){
		if(c[i]=='-'&&minu.upper_bound(i)!=minu.end()){
			int idx=*minu.upper_bound(i);
			ma=max(ma,now-(a[i]+getsum2(i+1,idx-1)-getsum(idx,n-1)));
		//	cout<<i<<" "<<idx<<" "<<now<<" "<<getsum2(i,idx-1)<<" "<<getsum(idx,n-1)<<endl;
		}
		now=sum2[i];
	}
	cout<<ma;
}