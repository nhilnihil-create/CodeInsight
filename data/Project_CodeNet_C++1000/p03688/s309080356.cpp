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
int arr[maxn];
int main()
{
	int n;scanf("%d",&n);
	int maxi=-INF;int mini=INF;
	int minicnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		maxi=max(maxi,arr[i]);
		mini=min(mini,arr[i]);
	}
	for(int i=1;i<=n;i++){
		if(arr[i]==mini) minicnt++;
	}
	if(maxi-mini>1||maxi>n-1){
		puts("No");
	}else if(maxi==mini){
		if(mini==n-1||mini==1) puts("Yes");
		else{
			if(n/mini>=2){
				puts("Yes");
			}else{
				puts("No");
			}
		}
	}else if(maxi!=mini){
		int x=n-minicnt;
		int y=maxi-minicnt;
		if(y==0) puts("No");
		else{
			if(x/y<2) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}