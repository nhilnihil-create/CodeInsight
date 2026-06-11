#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
ll mul_value(long long tp, long long ti)
{
    ll c, ans;
    if(tp<ti) return 0;
    else if(tp%ti == 0)
    {
        ans = tp/ti;
        return ans;
    }
    else
    {
        ans = tp/ti + 1;
        return ans;
    }
}
int main()
{
    speed_up;
    ll n, sum, tp = 0, ap = 0, ti, ai, a, b;
    cin>>n;
    while(n--)
    {
        cin>>ti>>ai;
        if(ti>tp && ai>ap)
        {
            tp = ti;
            ap = ai;
        }
        else
        {
            a = mul_value(tp, ti);
            b = mul_value(ap, ai);
            a = max(a, b);
            tp = ti * a;
            ap = ai * a;
        }
    }

    sum = tp + ap;
    cout<<sum<<endl;

return 0;
}

