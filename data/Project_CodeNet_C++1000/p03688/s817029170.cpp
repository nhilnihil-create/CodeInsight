#include<bits/stdc++.h>
using namespace std;

void fail(){
	cout<<"No"<<endl;
	exit(0);
}
int a[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],m=max(m,a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]<m-1)
			fail();
		else if(m-1==a[i])	
			s++;
	if(s==0){
		if(m==n-1||m<=n/2)	cout<<"Yes"<<endl;
		else fail();
		return 0;
	}
	if(s>=m)	fail();
	if((m-s)*2>n-s)
		fail();
	else
		cout<<"Yes"<<endl;
}

