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
int main(){
	set<int>s;
	for(int i=0;i<3;i++){
		int x;
		scanf("%d",&x);
		s.insert(x);
	} 
	printf("%d\n",s.size());
	return 0;
}