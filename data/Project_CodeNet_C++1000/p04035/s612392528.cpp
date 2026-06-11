#include<bits/stdc++.h>
using namespace std;

long long n,L,a[100005],last=0,ansl,ansr,l=0,r,sum[100005];

int main(){
	cin>>n>>L;sum[0]=0;ansl=0,ansr=n;
	for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
	//找到一段最小的区间,使得l---R>=L 
	for(r=1;r<=n;r++){
		while(sum[r]-sum[l+1]>=L)l++;
		if(r-l<ansr-ansl&&sum[r]-sum[l]>=L){
			ansr=r;
			ansl=l;
		}
	}
	//r----l+2内大于L
	if((sum[ansr]-sum[ansl]<L)||(sum[n]<L)){
		cout<<"Impossible"<<endl;
		exit(0);
	} 
	ansl++;//
	l=ansl,r=ansr;
	if(r-l+1<=2){
		cout<<"Possible"<<endl;
		for(int i=1;i<l;i++)cout<<i<<endl;
		for(int i=n-1;i>=r;i--)cout<<i<<endl;
		if(r-l+1==2)cout<<l<<endl;
	}
	else cout<<"Impossible"<<endl;
}