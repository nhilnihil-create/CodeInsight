#include<bits/stdc++.h>
using namespace std;
long long dp[41][401][401] = {};
class mix{
public:
    int a;
    int b;
    int p;
};
bool cmp(mix a,mix b)
{
    return (a.p < b.p);
}
int min_cost(int n,mix c[],int i,int a,int b,int r1,int r2)
{
    if(i == n)
        return INT_MAX;
    int gcd = __gcd(r1,r2);
    if(gcd != 0 && (r1/gcd) == a && (r2/gcd) == b)
        return 0;
    if(dp[i][r1][r2])
        return dp[i][r1][r2];
    long long c1 = (long long)c[i].p + (long long)min_cost(n,c,i + 1,a,b,r1 + c[i].a,r2 + c[i].b);
    long long c2 = (long long)min_cost(n,c,i + 1,a,b,r1,r2);
    dp[i][r1][r2] = min(c1,c2);
    return min(c1,c2);
}
int main()
{
    int n,a,b,i;
    cin>>n>>a>>b;
    mix c[n];
    for(i = 0; i < n; i++)
    {
        int f,s,t;
        cin>>f>>s>>t;
        c[i].a = f;
        c[i].b = s;
        c[i].p = t;  
    }
    sort(c,c + n,cmp);
    if(min_cost(n,c,0,a,b,0,0) != INT_MAX)
        cout<<min_cost(n,c,0,a,b,0,0)<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}