#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1e9
int n;
int a[111111],b[111111];
vector<int>v[111111];
int f[111111],s[111111];
int F,S;
queue<int>q;
signed main(){
	cin>>n;
	rep(i,n-1){
		cin>>a[i]>>b[i];
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	fill(f,f+n+1,INF);
	f[1]=0;
	q.push(1);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i:v[t]){
			if(f[i]>f[t]+1){
				f[i]=f[t]+1;
				q.push(i);
			}
		}
	}
	fill(s,s+n+1,INF);
	s[n]=0;
	q.push(n);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i:v[t]){
			if(s[i]>s[t]+1){
				s[i]=s[t]+1;
				q.push(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]<=s[i])F++;
		else S++;
	}
	if(F>S)puts("Fennec");
	else puts("Snuke");
	return 0;
}
