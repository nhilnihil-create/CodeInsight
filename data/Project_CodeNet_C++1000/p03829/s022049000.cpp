#include<bits/stdc++.h>
using namespace std;
long long s[100005];
int main(){
	long long n,a,b,i,num=0;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
		cin>>s[i];
	for(i=1;i<n;i++)
		num+=min(a*(s[i+1]-s[i]),b);
	cout<<num<<endl;
}