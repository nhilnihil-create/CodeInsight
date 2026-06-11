#include <cstdio>
#include <algorithm>
#include <cstring> 
#define MAXN 5050
#define ll long long
using namespace std;
int a[MAXN], dp[MAXN][MAXN];
int n, k;
/*  
	dp[i][j]表示从前i个元素中是否可以选择一些数使得它们的和为j
				  一般情况：dp[i,j] = dp[i-1][j];
	状态转移方程：当j大于ai时：dp[i,j] = dp[i-1,j]|dp[i-1,j-ai] 
	1、排序 
	2、如果ai是不必要的元素，那么ai之前的元素都是不必要的，因此二分查找ai出现的位置 
    3、使用check函数判断当前元素x是不是必要的 ,是则返回true 不是返回false
		如果x是有用的元素，那么一定可以从n个元素中选择一些元素之和在[k-a[s], k)之间，遍历dp[n][(k-a[i], k)]即可 
		使用dp判断出所有的存在于这个区间的元素，如果能找到，说明x是有用的元素，返回true 
*/ 
bool check(int x) { 
	memset(dp, 0, sizeof(dp));
	if(x==1) {
		dp[2][0] = 1;
        dp[2][a[2]] = 1;
        for(int i = 3; i <= n; i++) 
            for(int j = 0; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= a[i])
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i]];    
            }
	} 
	else {
		dp[1][0] = 1;
		dp[1][a[1]] = 1;
		for(int i = 2; i <= n; i++) 
			for(int j = 0; j <= k; j++) {
				dp[i][j] = dp[i-1][j];
				if(j >= a[i] && x != i) 
					dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i]];
			}
	}
	for(int i = k-a[x]; i < k; i++)
		if(dp[n][i])
			return true;
	return false;	 
}
int main() {

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] > k) a[i] = k;
	}
	if(n==1) {
		if(a[1] >= k) printf("0\n");
		else printf("1\n");
		return 0;
	}
	sort(a+1, a+1+n);
	int l = 0, r = n+1;
	while(l+1 < r) {
		int mid = (l+r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%d\n", l);
	return 0;
}