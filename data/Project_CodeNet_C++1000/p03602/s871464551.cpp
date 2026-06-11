#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

signed main(){
	int n;cin>>n;
	vector<vector<int>> a(n,vector<int>(n));
	vector<vector<int>> b(n,vector<int>(n));
	vector<vector<bool>> c(n,vector<bool>(n,true));


rep(i,n)rep(j,n){cin>>a[i][j];b[i][j]=a[i][j];}

rep(i,n)rep(j,n)rep(k,n)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);

rep(i,n)rep(j,n){if(a[i][j]!=b[i][j])cout<<-1<<endl,exit(0);}

rep(i,n)rep(j,n)rep(k,n){
if(i==k||k==j)continue;
if(a[i][j]==a[i][k]+a[k][j])c[i][j]=false;
}
int ret=0;
rep(i,n)rep(j,n){if(c[i][j] && i<j)ret+=a[i][j];}
cout<<ret<<endl;
//rep(i,n){rep(j,n){cout<<a[i][j]<<" ";}cout<<endl;}
//  cout<<ret<<endl;
// rep(i,n){rep(j,n){cout<<c[i][j]<<" ";}cout<<endl;}
 
}