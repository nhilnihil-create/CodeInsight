#include<bits/stdc++.h>
using namespace std;

void fail(){
	cout<<"NO"<<endl;
	exit(0);
}
int a[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	a[n]=a[0];
	long long int tot=0;
	for(int i=0;i<n;i++)
		tot+=a[i];
	long long int sum=1LL*n*(n+1)/2;
	if(tot%sum!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	long long int k=tot/sum;
	for(int i=0;i<n;i++){
		long long int x=k-a[i+1]+a[i];
		if(x<0||x%n!=0)
			fail();
	}
	cout<<"YES"<<endl;
}
