#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[MAX],mx[MAX],sum,ans;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n*3; i++)
        cin>>arr[i];
    priority_queue<int>x,y;
    for(int i=1; i<=n; i++)
    {
        x.push(arr[i]*-1);
        mx[i]=mx[i-1]+arr[i];
    }
    for(int i=n+1; i<=n*2; i++)
    {
        int cur=x.top()*-1;
        mx[i]=mx[i-1];
        if(cur<arr[i]);
        {
            x.pop();
            mx[i]-=cur;
            mx[i]+=arr[i];
            x.push(arr[i]*-1);
        }
    }
    for(int i=n*2+1; i<=n*3; i++)
    {
        y.push(arr[i]);
        sum+=arr[i];
    }
    ans=mx[2*n]-sum;
    for(int i=2*n; i>n; i--)
    {
        if(y.top()>arr[i])
        {
            sum-=y.top();
            y.pop();
            sum+=arr[i];
            y.push(arr[i]);
        }
        ans=max(ans,mx[i-1]-sum);
    }
    cout<<ans<<endl;


    return 0;
}
