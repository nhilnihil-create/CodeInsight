#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

// https://atcoder.jp/contests/abc069/submissions/6395790 写経

ll c[10002];
ll glid[101][101];
int main() {
	ll h,w,C;
	cin>>h>>w>>C;
	for(int i=0;i<C;i++){
		cin>>c[i];
	}
	ll k=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(c[k]==0){
				k++;
			}
			c[k]--;
			glid[i][j]=k+1;
		}
	}
	bool turn=false;
	for(int i=0;i<h;i++){
		if(turn==false){
			for(int j=0;j<w;j++){
				cout << glid[i][j]<< " ";
			}
		}
		else{
			for(int j=w-1;j>=0;j--){
				cout << glid[i][j]<<" ";
			}
		}
		cout << endl;
		if(turn){
			turn=false;
		}
		else{
			turn=true;
		}
	}
	return 0;
}
