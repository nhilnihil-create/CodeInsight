#include <bits/stdc++.h> 
using namespace std;
int a[1000005],b[1000005];
int n;
int check(int x)
{
	for(int i = 1;i < n<<1;i ++) b[i] = a[i] >= x;
    int p = !(n&1);int cur = 1e9;
    int ret = b[n]^p;
    for(int i = n-1;i >= 1;i --)
        if(b[i] == b[i+1] && n-i < cur)
            cur = n-i,ret = b[i];
    for(int i = n+1;i <= 2*n-1;i ++)
        if (b[i] == b[i-1] && i-n < cur)
		{
            cur = i-n;
            ret = b[i];
        }
    return ret;
}
int main()
{
	scanf("%d",&n);
    for(int i = 1;i < 2*n;i ++) scanf("%d",&a[i]);
    int l = 1,r = 2*n-1;
    while(l < r)
	{
        int mid = (l+r+1)>>1;
        if(check(mid)) l = mid;
		else r = mid-1;
    }
    printf("%d\n",l);
    return 0;
}