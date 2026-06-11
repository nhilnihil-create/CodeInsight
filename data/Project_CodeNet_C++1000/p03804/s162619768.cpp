#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

char g[55][55],c[55][55];

int main(){
	int n,m;
	cin>>n>>m;
	rep(i,n){
		rep(j,n){
			cin>>g[i][j];
		}
	}

	rep(i,m){
		rep(j,m){
			cin>>c[i][j];
		}
	}
	rep(i,n-m+1){
		rep(j,n-m+1){
			bool ok=1;
			rep(k,m){
				rep(q,m){
					if(g[k+i][q+j]!=c[k][q]){
						ok=0;
					}
				}
			}
			if(ok){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
}