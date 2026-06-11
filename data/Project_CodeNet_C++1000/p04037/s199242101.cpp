#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#define szxb 100010
using namespace std;
int n,a[szxb];
inline bool cmp(int x,int y){return (x>y);}
signed main()
{
	scanf("%d",&n);int n1(0),n2(0);
	for(register int i(1);i^(n+1);i++){scanf("%d",&a[i]);}sort(a+1,a+n+1,cmp);while(a[n1+1]>=(n1+1)){n1++;}while(a[n1+n2]>=n1){n2++;}
	puts(((((a[n1]-n1+1)&1)&&(n2&1))?("Second"):("First")));
	return 0;
}