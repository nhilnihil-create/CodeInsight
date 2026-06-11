#include<iostream>
#include<cmath>
using namespace std;
long long a[200050];
int main(){

	int n,i,j;
	long long x=0,y=0,sum=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		y+=a[i];
	}
	sum = abs(y-a[0]*2);
	for(i=0;i<n-1;i++){
		x+=a[i];
		y-=a[i];
		if(abs(x-y)<sum) sum=abs(x-y);
	}
	cout<<sum;
	return 0;
}