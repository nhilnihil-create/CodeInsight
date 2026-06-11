#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,k,a;vector<int> e[2010];
int t(int x,int p,int d,int mx){
	if(d==mx)return 1;
	int s=1;
	for(int i:e[x])if(i!=p)s+=t(i,x,d+1,mx);
	return s;
}
int main(){
	cin>>n>>k;
 	REP(i,n-1){
		int a,b;cin>>a>>b;a--;b--;
		e[a].push_back(b),e[b].push_back(a);
	}
	if(k%2==0)REP(i,n)a=max(a,t(i,-1,0,k/2));
	else REP(i,n)for(int j:e[i])a=max(a,t(i,j,0,k/2)+t(j,i,0,k/2));
	cout<<n-a;
}