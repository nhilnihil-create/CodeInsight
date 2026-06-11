#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,m; cin>>n>>m;
	vector<vector<char>> v(n,vector<char>(n));
	rep(i,n){
		string s; cin>>s;
		rep(j,n){
			v[i][j]=s[j];
		}
	}
	string ts;
	rep(i,m){
		string s; cin>>s;
		ts+=s;
	}
	rep(i,n-m+1){
		rep(j,n-m+1){
			string vs;
			for(int k=i; k<i+m; k++){
				for(int l=j; l<j+m; l++){
					vs+=v[k][l];
				}
			}
			if(vs==ts) {cout<<"Yes"<<endl; return 0;}
		}
	}
	cout<<"No"<<endl;
}