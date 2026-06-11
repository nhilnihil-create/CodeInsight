#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h,w; cin>>h>>w;
	h+=2; w+=2;
	vector<vector<char>> v(h,vector<char>(w));
	rep(i,h){
		rep(j,w){
			v[i][j]='#';
		}
	}
	
	for(int i=1; i<h-1; i++){
		string s; cin>>s;
		rep(j,w-2){
			v[i][j+1]=s[j];
		}
	}
	
	rep(i,h){
		rep(j,w){		
			cout<<v[i][j];
		}
		cout<<endl;
	}
}