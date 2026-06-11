#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iomanip>
#include <numeric>
#include <list>
#include <bitset>
#include <ctime>
#include <deque>
#include <functional>
int a[200005],n,l,r,mid;

inline bool check(const int &k)
{
    if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))
        return 1;
    if((k<a[n-1]&&k<a[n])||(k<a[n]&&k<a[n+1]))
        return 0;
    for (int i=1;i<n-1;i++)
    {
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))
            return 1;
        if((k<a[n+i]&&k<a[n+i+1])||(k<a[n-i]&&k<a[n-i-1]))
            return 0;
    }
    return (a[1]<=k&&a[1]<=k);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<n<<1;i++) scanf("%d",a+i);
    for (r=(n<<1)-1,mid=l+r>>1;l<r;mid=l+r>>1) if (check(mid)) r=mid;else l=mid+1;
    printf("%d",l);
}
