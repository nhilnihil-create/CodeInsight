#include<bits/stdc++.h>
using namespace std;

int a[20001],b[20001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=1+30000*(i-1),b[i]=1+30000*(n-i);
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[x]+=i;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<b[i]<<' ';
	cout<<endl;
}

