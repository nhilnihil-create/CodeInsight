#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e6+7;
const int mod=1e9+7;
int f1[MAX],f2[MAX];
int n,k,l;
map<int,map<int,int>>mp;
void init(int n){
	for(int i=0;i<=n;i++)
		f1[i]=f2[i]=i;
}
int FIND(int x,int f[]){
	return  f[x]==x?x:f[x]=FIND(f[x],f);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>l;
	init(n);
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		int fx=FIND(x,f1),fy=FIND(y,f1);
		if(fx!=fy) f1[fx]=fy;
	}
	for(int i=1;i<=l;i++){
		int x,y;cin>>x>>y;
		int fx=FIND(x,f2),fy=FIND(y,f2);
		if(fx!=fy) f2[fx]=fy;
	}
	for(int i=1;i<=n;i++)
		mp[FIND(i,f1)][FIND(i,f2)]++; 
	 for(int i=1;i<=n;i++)
	 	cout<<mp[FIND(i,f1)][FIND(i,f2)]<<" "; 
	
   return 0;
} 