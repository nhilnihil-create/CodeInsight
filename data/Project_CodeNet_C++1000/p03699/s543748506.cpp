#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,sum=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(sum%10!=0){
			cout<<sum<<endl;
			return 0;
		}
		else
			for(int j=1;j<=n;j++)
				if(a[i]%10!=0){
					sum-=a[i];
					break;
				}
	}
	
	cout<<0<<endl;
	return 0;
}