#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
char s[N];
int main(){
	scanf("%s",s);
	int ans=0;
	char x=s[0];
	for(int i=0;s[i];i++){
		 if(s[i]!=x) ans++,x=s[i];
	}
	printf("%d\n",ans); 
	return 0;
}