#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h,w; cin>>h>>w;
	h*=2;
	vector<vector<char>> v(h,vector<char>(w));
	for(int i=0; i<h; i+=2){
		rep(j,w){
			cin>>v[i][j];
		}
		rep(j,w){
			v[i+1][j]=v[i][j];
		}
	}
	rep(i,h){
		rep(j,w){
			cout<<v[i][j];
		}
		cout<<endl;
	}
}