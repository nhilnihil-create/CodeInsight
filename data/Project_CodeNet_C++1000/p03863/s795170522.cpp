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
	int n=strlen(s);
	if(s[0]==s[n-1]) n--;
	puts(n&1?"First":"Second");
	return 0;
}