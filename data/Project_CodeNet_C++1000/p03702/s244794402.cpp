#include<bits/stdc++.h>
using namespace std;
long long n,a,b,h[100003],l,r,tmp[100003];
bool check(long long times){
	for(int i=0;i<n;i++)tmp[i]=max(h[i]-b*times,0ll);
	for(int i=0;i<n;i++)
		if(tmp[i]>0)
			times=times-(tmp[i]-1)/(a-b)-1;
	return times>=0;
}
int main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)cin>>h[i];
	l=1,r=1000000000;
	while(l!=r){
		long long mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l;
}