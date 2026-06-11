#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005],b[100005],c[100005];
ll sum;
ll M;
ll amari(ll i,ll j){
	if(i%j>=0){
		return i%j;
	}else{
		return i%j+j;
	}
}
int main(void){
	cin>>n;
	ll SUM=n*(n+1)/2;
	cin>>a[0];
	sum=sum+a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		sum=sum+a[i];
		b[i-1]=a[i]-a[i-1];
	}
	b[n-1]=a[0]-a[n-1];
	if(sum%SUM!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	ll k=sum/SUM;
	for(int i=0;i<n;i++){
		b[i]=b[i]-k;
		if(b[i]%n!=0||b[i]>0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}
