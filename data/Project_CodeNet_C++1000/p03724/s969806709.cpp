#include<bits/stdc++.h>
using namespace std;

int a[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		a[u]^=1;
		a[v]^=1;
	}
	cout<<(accumulate(a+1,a+n+1,0)==0?"YES":"NO")<<endl;
}

