#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define ROF(i,a,b) for(int i = (a);i>=(b);i--)
#define MST(a,x) memset(a,x,sizeof(a))
#define ll long long
#define PB push_back
#define PH push
#define MP make_pair
#define FT first
#define SD second
#define N 100005
#define M 51
#define INF 1000000007
#define MOD 1000000007
#define MOD2 1000000009
#define eps 1e-14
using namespace std;
inline int Max(int a,int b)
{
    return (((b-a)>>(32-1))&(a^b))^b;
}
inline int Min(int a,int b)
{
    return (((b-a)>>(32-1))&(a^b))^a;
}

int n;
int a[N];
int gcder(int a,int b)
{
    return a == 0?b:gcder(b%a,a);
}
int calc()
{
    if(n == 1)return a[1];
    int ret = gcder(a[1],a[2]);
    FOR(i,3,n)ret = gcder(ret,a[i]);
    return ret;
}
int main()
{
    while(cin>>n)
    {
        int odd = 0,even = 0;
        FOR(i,1,n)
        {
            cin>>a[i];
            if(a[i]%2)odd++;
            else even++;
        }
        int win,rev = 0;
        while(1)
        {
            if(even%2 == 0&&odd == 1)
            {
                int p;
                FOR(i,1,n)if(a[i]%2)p = i;
                if(a[p] == 1)
                {
                    win = 1;
                    break;
                }
                a[p]--;
                int gcd = calc();
                odd = even = 0;
                FOR(i,1,n)
                {
                    a[i]/=gcd;
                    if(a[i]%2)odd++;
                    else even++;
                }
                rev = 1-rev;
            }
            else
            {
                if(odd == n)win = 1;
                else if(even%2)win = 0;
                else if(odd>=2)win = 1;
                break;
            }
        }
        if(rev)win = 1-win;
        if(win == 0)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}
