#include<bits/stdc++.h>
using namespace std;
int k[101];
int main(){
	int n,i,z=0;
	cin>>n;
	for(i=1;i<=n*2;i++)
		cin>>k[i];
	sort(k+1,k+n*2+1);
	for(i=1;i<=n*2;i+=2)
		z+=k[i];
	cout<<z;
}