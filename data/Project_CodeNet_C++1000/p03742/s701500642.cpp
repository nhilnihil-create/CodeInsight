#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
#define ULL unsigned long long
LL read(){
	LL f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
#define MAXN 200005
#define INF 0x3f3f3f3f
int main(){
	LL X=read(),Y=read();
	puts(fabs(X-Y)>1?"Alice":"Brown");
	return 0;
}//