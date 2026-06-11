#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#define mst(a,b) memset((a),(b),sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=1e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int ans[505][505];
int main()
{
	int H,W,h,w;
	int val=2000;
	scanf("%d %d %d %d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0){
		puts("No");
	}else{
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				if(i%h==0&&j%w==0){
					ans[i][j]=-(h*w-1)*val-1;
				}else{
					ans[i][j]=val;
				}
			}
		}
		puts("Yes");
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				printf("%d%c",ans[i][j],j==W?'\n':' ');
			}
		}
	}
	return 0;
}