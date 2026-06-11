#include<iostream>
#include <cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[200005];
long long b[200005];
int main(){
	long long n;
	long long sum1=0;
	long long sum=0;
	long long temp=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	for(int i=0;i<n-1;i++){
		//b[i]用来存结果
		sum1+=a[i];
		temp=sum-sum1;
	//	cout<<"sum1="<<sum1<<endl;
	//	cout<<"temp="<<temp<<endl;
		
		b[i]=abs(sum1-temp);
//		cout<<"b["<<i<<"]="<<b[i]<<endl;
		
		
	}
	sort(b,b+n-1);
//	for(int i=0;i<n-1;i++)
//	{
//	cout<<"b["<<i<<"]="<<b[i]<<endl;
//	}
	printf("%lld",b[0]);
	return 0;
} 
