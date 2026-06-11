#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int w,h,n; cin>>w>>h>>n;
	vector<vector<int>> v(w,vector<int>(h));
	rep(i,n){
		int x,y,a; cin>>x>>y>>a;
		if(a==1){
			for(int i=0; i<x; i++){
				for(int j=0; j<h; j++){
					v[i][j]=1;
				}
			}
		}
		if(a==2){
			for(int i=x; i<w; i++){
				for(int j=0; j<h; j++){
					v[i][j]=1;
				}
			}
		}
		if(a==3){
			for(int i=0; i<w; i++){
				for(int j=0; j<y; j++){
					v[i][j]=1;
				}
			}
		}
		if(a==4){
			for(int i=0; i<w; i++){
				for(int j=y; j<h; j++){
					v[i][j]=1;
				}
			}
		}
	}
	int cnt=0;
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			if(v[i][j]==0) cnt++;
		}
	}
	cout<<cnt<<endl;
}