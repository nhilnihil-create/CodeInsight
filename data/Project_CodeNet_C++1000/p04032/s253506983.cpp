#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
char a[N];
int main(){
	scanf("%s",a);
	int l=strlen(a);
	for(int i=0;i<l-1;i++){
		if(a[i]==a[i+1]){
			printf("%d %d\n",i+1,i+2);
			return 0;
		}
		if(a[i]==a[i+2]){
			printf("%d %d\n",i+1,i+3);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}