#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int n,k,l;
int f1[N],f2[N],sum1[N],sum2[N];
int getf1(int v){
	if(v==f1[v]){
		return f1[v];
	}else{
		f1[v]=getf1(f1[v]);
		return f1[v];
	}
}
void merge1(int u,int v){
	int t1=getf1(u);
	int t2=getf1(v);
	if(t1!=t2){
		f1[max(t1,t2)]=min(t1,t2);
		sum1[min(t1,t2)]+=sum1[max(t1,t2)];
	}
}


int getf2(int v){
	if(v==f2[v]){
		return f2[v];
	}else{
		f2[v]=getf2(f2[v]);
		return f2[v];
	}
}
void merge2(int u,int v){
	int t1=getf2(u);
	int t2=getf2(v);
	if(t1!=t2){
		f2[max(t1,t2)]=min(t1,t2);
		sum2[min(t1,t2)]+=sum2[max(t1,t2)];
	}
	
}
void init(){
	for(int i=0;i<=n;i++) f1[i]=i;
	for(int i=0;i<=n;i++) f2[i]=i;
	for(int i=0;i<=n;i++) sum1[i]=1,sum2[i]=1;
}
map<pair<int,int>,int> mp;
signed main(){
	cin>>n>>k>>l;
	init();
	for(int i=1;i<=k;i++){
		int a,b;cin>>a>>b;
		merge1(a,b);
	}
	for(int i=1;i<=l;i++){
		int a,b;cin>>a>>b;
		merge2(a,b);
	}
	for(int i=1;i<=n;i++){
		
		mp[make_pair(getf1(i),getf2(i))]++;
	}
	for(int i=1;i<=n;i++)
		cout<<mp[make_pair(getf1(i),getf2(i))]<<" ";
	return 0;
}