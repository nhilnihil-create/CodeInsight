#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int arr[N];
stack<int> q;
int l[N],r[N];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	for(int i=0;i<=n+1;i++){
		l[i]=1;r[i]=n;
	}
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		while(!q.empty()&&arr[q.top()]>arr[i]) q.pop();
		if(!q.empty()) l[i]=q.top()+1;else l[i]=1;
		q.push(i);
	}
	
	while(!q.empty()) q.pop();
	for(int i=n;i>=1;i--){
		while(!q.empty()&&arr[q.top()]>arr[i]) q.pop();
		if(!q.empty()) r[i]=q.top()-1;
		q.push(i);
	}
	/*
	for(int i=1;i<=n;i++) cout<<l[i]<<" ";
	cout<<'\n';
	for(int i=1;i<=n;i++) cout<<r[i]<<" ";
	cout<<'\n';
	*/
	int ans=0;
 	for(int i=1;i<=n;i++) ans+=arr[i]*((i-l[i]+1)*(r[i]-i+1));
	cout<<ans;
	return 0;
}