#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	int n,m,a,b,c[100]={};
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		c[a]++;
		c[b]++;
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<endl;
	}
	return(0);
}