  /*  HARD WORK FOREVER PAYS  */
#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
typedef pair<int,pair<int,int>> PII;
int n,m;
char grid1[55][55],grid2[55][55];
int compare(int i,int j){
	int l,k,o=0,p=0;
	for(l=i;l<n&&o<m;l++,o++){
		p=0;
		for(k=j;k<n&&p<m;k++,p++){
			if(grid1[l][k]!=grid2[o][p]){
				return 0;
			}
		}
	}
	if(o<m||p<m){

		return 0;
	}
	return 1;
}
int main() 
{ 
	turbo();
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>grid1[i][j];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			cin>>grid2[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int ans=compare(i,j);
			if(ans){
				cout<<"Yes\n";
				return 0;
			}
		}
	}
	cout<<"No\n";
    return 0; 
} 