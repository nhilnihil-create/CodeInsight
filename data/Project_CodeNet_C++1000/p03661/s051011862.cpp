#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
ll t=1000000000000;
int main(){
	int n;
	cin>>n;
	ll a[n],sum=0,sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll ans=0;
	for(int i=0;i<n-1;i++){
		sum1=sum1+a[i];
		ans=sum-sum1*2;
		ans=abs(ans);
		if(t>ans){
			t=ans;
		}
	}
	cout<<t<<endl;
    return 0;
}
