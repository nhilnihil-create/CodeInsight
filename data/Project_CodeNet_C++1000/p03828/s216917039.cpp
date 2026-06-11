#include<bits/stdc++.h>
using namespace std;
long long c[1005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t=i;
		for(int j=2;j<=i;j++)
			while(t%j==0){
				t/=j;
				c[j]++;
			}
	}
	long long a=1;
	for(int i=2;i<=n;i++)
		a=a*(c[i]+1)%1000000007;
	cout<<a;
	return 0;
}