#include<bits/stdc++.h>
using namespace std;
int n,a[250],s=0;
int main(){
	cin>>n;
	for(int i=1;i<=n*2;i++)cin>>a[i];
	sort(a+1,a+1+2*n);
	for(int i=1;i<=n;i++)s+=a[i*2-1];
	cout<<s<<endl;
}