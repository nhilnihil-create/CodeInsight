#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
using namespace std;
typedef long long LL;
int n;
LL a[300050],sum1[300050],sum2[300050],SUM1,SUM2,Max;
priority_queue<LL, vector<LL>, less<LL> >q1;
priority_queue<LL, vector<LL>, greater<LL> >q2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*3;i++) scanf("%lld",&a[i]);
	sum1[0]=0;
	sum2[n*3+1]=0;
	SUM1=0;
	SUM2=0;
	for(int i=1;i<=n;i++){
		q2.push(a[i]);
		SUM1+=a[i];
	}
	sum1[n]=SUM1;
	for(int i=n*3;i>=2*n+1;i--){
		q1.push(a[i]);
		SUM2+=a[i];
	}
	sum2[2*n+1]=SUM2;
	int l=n+1,r=2*n;
	while(l<=r){
		if(a[l]>q2.top()){
			SUM1-=q2.top();
			SUM1+=a[l];
			q2.pop();
			q2.push(a[l]);
		}
		sum1[l]=SUM1;
		l++;
	}
	l=n+1,r=2*n;
	while(l<=r){
		if(q1.top()>a[r]){
			SUM2-=q1.top();
			SUM2+=a[r];
			q1.pop();
			q1.push(a[r]);
		}
		sum2[r]=SUM2;
		r--;
	}
	Max=-1e18;
	for(int i=n;i<=2*n;i++){
		if(sum1[i]-sum2[i+1]>Max) Max=sum1[i]-sum2[i+1];
	}
	printf("%lld\n",Max);
}