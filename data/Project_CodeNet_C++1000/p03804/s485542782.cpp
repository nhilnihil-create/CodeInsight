#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
char a[55][55],b[55][55];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>b[i][j];
		} 
	}
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++){
			int cnt=0,s=0,x=1,y=1;
			for(int k=i;k<=n&&s<m*m;k++){
				for(int l=j;l<=n&&s<m*m;l++){
					s++;
					if(a[k][l]==b[x][y]) cnt++;
					//printf("(%d,%d),%d\n",k,l,cnt);
					y++;
					if(y==m+1) x++,y=1;
					if(l<=n&&l==j+m-1) break; 
					//printf("(%d,%d),%d\n",k,l,cnt);
				}
			}
			if(cnt==m*m) return  puts("Yes"),0;
		}
	puts("No");
	return 0;
}