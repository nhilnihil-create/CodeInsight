#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	n+=2,m+=2;
	char c[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c[i][j]='#';
		}
	}

	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			char g;
			cin>>g;
			c[i][j]=g;
		}
	}
	
for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<c[i][j];
		}
		cout<<'\n';
	}

	
	
}