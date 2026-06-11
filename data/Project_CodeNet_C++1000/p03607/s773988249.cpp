#include<bits/stdc++.h>
using namespace std;
int n,a[100001],sum,i;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	i=1;
	while(i<=n){
		if(a[i]==a[i+1])i+=2;
		else{
			i++;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
