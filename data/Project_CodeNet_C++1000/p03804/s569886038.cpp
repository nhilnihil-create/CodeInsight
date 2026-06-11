#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
char a[55][55],b[55][55];
signed main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) cin>>b[i][j];
	for(int i=0;i+m<=n;i++){
		for(int j=0;j+m<=n;j++){
			bool check=1;
			for(int ii=0;ii<m;ii++)
				for(int jj=0;jj<m;jj++)
					if(a[i+ii][j+jj]!=b[ii][jj])
						check=0;
			if(check){
				cout<<"Yes";
				re 0;
			}	
		}
	}
	cout<<"No";
	re 0;
}