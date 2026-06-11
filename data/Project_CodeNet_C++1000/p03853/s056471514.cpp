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
char s[105][105];
int main(){
	int h,w;cin>>h>>w;
	for(int i=1;i<=h;i++) cin>>(s[i]+1);
	for(int i=1;i<=2*h;i++){
		for(int j=1;j<=w;j++){
			printf("%c",s[(i+1)/2][j]);
		}
		puts("");
	}
	return 0;
}