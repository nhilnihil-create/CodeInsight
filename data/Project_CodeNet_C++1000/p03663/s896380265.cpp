#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
void ask(ll x)
{
    printf("? %lld\n",x);
    fflush(stdout);
}
void res(ll x)
{
    printf("! %lld\n",x);
    fflush(stdout);
}
char op[2];
bool check(ll x)
{
    ask(x);
    scanf("%s",op);
    return (op[0]=='Y');
}
ll po[11];
int main() {
    //freopen(".in", "r", stdin);
    po[0]=1;
    for(int i=1;i<=10;i++) po[i]=po[i-1]*10;
    int pos=-1;
    ll ans;
    for(int i=0;i<=10;i++)
    {
        ask(po[i]);
        scanf("%s",op);
        if(op[0]=='N')
        {
            pos=i;
            ans=po[i];
            break;
        }
    }
    if(pos==-1)
    {
        for(int i=0;i<=10;i++)
        {
            ask(po[i]+1);
            scanf("%s",op);
            if(op[0]=='Y')
            {
                ans=po[i];
                break;
            }
        }
        res(ans);
    }
    else
    {
        ll ans=0;
        for(int i=1;i<=pos-1;i++)
        {
            int l=0,r=9;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(check(ans*10LL+mid)) l=mid+1;
                else r=mid-1;
            }
            ans = ans *10LL + r;
        }
        ans = ans*10LL;
        int flag=0;
        ans=ans*10LL;
        for(int i=9;i>=0;i--)
        {
            if(check(ans+i*10LL)) flag=i;
            else break;
        }
        res((ans+flag*10)/10);
    }

    return 0;
}

