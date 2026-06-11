//InTheNameOfGod
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i,j,k) for(int i=j;i<k;++i)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define pb push_back
#define lb(i) i&(-i);
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn =1e5+5;
int n,a[maxn],s=0,cnt,p,re=0;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    rep(i,0,n)
    {
        cin>>a[i];
    }
    while(true)
    {
        cnt=0;
        s=0;
        p=0;
        rep(i,0,n)
        {
            if(a[i]&1)
            {
                cnt++;
                p=a[i];
            }
            else
            {
                s^=1;
            }
        }
        if(s)
        {
            break;
        }
        else if(cnt>1||p==1)
        {
            re^=1;
            break;
        }
        else
        {
            int g=0;
            rep(i,0,n)
            {
                if(a[i]&1)
                {
                    g=__gcd(a[i]-1,g);
                    a[i]--;
                }
                else g=__gcd(a[i],g);
            }
            rep(i,0,n)
            {
                a[i]/=g;
            }
            re^=1;
        }
    }
    if(re)
    {
        cout<<"Second";
    }
    else cout<<"First";
    return 0;
}
