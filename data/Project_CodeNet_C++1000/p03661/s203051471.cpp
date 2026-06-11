#include<iostream>
#include<cmath>
using namespace std;

long long int sa(long long int*a,int c,int d){
	long long int res=0;
	for(int i=c;i<=d;i++){
		res += a[i];
	}
	return res;
}


int main(void)
{
	int n = 0;
	cin>>n;
	long long int a[n]={0};
	long long int b[n+1]={0};
	long long int sac = 0;
	long long int pre = 0;long long int las = 0;long long int re = 0;
	for(int k=0;k<n;k++){
		long long int h =0;
		cin>>h;
		a[k]=h;
		b[k+1]=b[k]+h;
	}
	sac = sa(a,0,n-1);
	long long int res = 0;
	long long int min = 9223372036854775807;
	for(int i=0;i<n-1;i++)
	{
		res = abs(sac- 2*b[i+1]);
		if (res < min) min=res;
	}
	cout <<min;
	return 0;
}



