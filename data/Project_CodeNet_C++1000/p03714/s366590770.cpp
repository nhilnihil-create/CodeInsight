#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>q1,q2;
long long a[300010],f1[300010],f2[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,s1=0,s2=0,ans=-9e18;
	cin>>n;
	for(long long i=1;i<=3*n;i++){
		cin>>a[i];
		if(i<=n){
			s1+=a[i];
			q1.push(-a[i]);
		}
		if(i>2*n){
			s2+=a[i];
			q2.push(a[i]);
		}
	}
	f1[n]=s1;
	for(long long i=n+1;i<=2*n;i++)
	if(-q1.top()<a[i]){
		s1+=a[i]-(-q1.top());
		q1.pop();
		q1.push(-a[i]);
		f1[i]=s1;
	}
	else f1[i]=s1;
	f2[n*2]=s2;
	for(long long i=n*2-1;i>=n;i--)
	if(q2.top()>a[i+1]){
		s2+=a[i+1]-q2.top();
		q2.pop();
		q2.push(a[i+1]);
		f2[i]=s2;
	}
	else f2[i]=s2;
	for(long long i=n;i<=2*n;i++)
	ans=max(ans,f1[i]-f2[i]);
	cout<<ans<<"\n";
	return 0;
}
 