# include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int maxn = 1e5+3;
LL a[maxn*3], l[maxn], r[maxn];
priority_queue<LL, vector<LL>, greater<LL> >q;
priority_queue<LL>p;
int main()
{
    LL sum = 0, sum2=0, ans;
    int n, m;
    scanf("%d",&n);
    for(int i=1; i<=3*n; ++i)
    {
        scanf("%lld",&a[i]);
        if(i<=n) sum += a[i], q.push(a[i]);
        else if(i>2*n) sum2 += a[i], p.push(a[i]);
    }
    l[n] = sum;
    r[2*n+1] = sum2;
    for(int i=n+1; i<=2*n; ++i)
    {
        if(q.top() < a[i])
        {
            sum = sum - q.top() + a[i];
            q.pop();
            q.push(a[i]);
        }
        l[i] = sum;
    }
    r[2*n] = sum2;
    for(int i=2*n-1; i>=n; --i)
    {
        if(p.top() > a[i+1])
        {
            sum2 = sum2 - p.top() + a[i+1];
            p.pop();
            p.push(a[i+1]);
        }
        r[i] = sum2;
    }
    ans = l[n]-r[n];
    for(int i=n+1; i<=2*n; ++i)
        ans = max(ans, l[i]-r[i]);
    printf("%lld\n",ans);
    return 0;
}