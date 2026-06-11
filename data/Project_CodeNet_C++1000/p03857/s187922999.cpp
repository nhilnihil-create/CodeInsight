#include<bits/stdc++.h>
#define YY "YES\n"
#define NN "NO\n"
#define LL long long
#define mp make_pair
using namespace std;

int n,m,tt,tar,k,tmp,l,ans[200001],dsua[200001],dsub[200001];
vector<int> ar[200001];

int finda(int now){
	if (dsua[now]==now) return now;	
	return dsua[now]=finda(dsua[now]); 
}
int findb(int now){
	if (dsub[now]==now) return now;	
	return dsub[now]=findb(dsub[now]); 
}

int main(){
	int x,y;
	cin>>n>>k>>l;
	for (int i=1;i<=n;i++){
		dsua[i]=i;
		dsub[i]=i;
	}
	for (int i=1;i<=k;i++){
		cin>>x>>y;
		int a=finda(x);
		int b=finda(y);
		if (a!=b){
			dsua[a]=dsua[b];
		}
	}
	for (int i=1;i<=l;i++){
		cin>>x>>y;
		int a=findb(x);
		int b=findb(y);
		if (a!=b){
			dsub[a]=dsub[b];
		}
	}
	for (int i=1;i<=n;i++){
		finda(i);
		findb(i);
	}
	map<pair<int,int>,int> mpp;
	for (int i=1;i<=n;i++){
		mpp[mp(dsua[i],dsub[i])]++;
	}
	for (int i=1;i<=n;i++){
		cout<<mpp[mp(dsua[i],dsub[i])]<<" ";
	}
}