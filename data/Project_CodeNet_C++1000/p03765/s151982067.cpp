#include<bits/stdc++.h>
using namespace std;

const int N=100100;
int n,m,a[N],b[N],q;
char S[N],T[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>S>>T>>q;n=strlen(S);m=strlen(T);
	for(int i=1;i<=n;++i)a[i]=a[i-1]+(S[i-1]=='A'?1:-1);
	for(int i=1;i<=m;++i)b[i]=b[i-1]+(T[i-1]=='A'?1:-1);
	for(;q --> 0;){
		int x,y,z,w;cin>>x>>y>>z>>w;
		int res=(a[y]-a[x-1])-(b[w]-b[z-1]);
		cout<<(res%3?"NO\n":"YES\n");
	}
	return 0;
}
