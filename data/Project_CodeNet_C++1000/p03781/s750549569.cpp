#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=200005;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
ll x;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>x)
    {
        ll sum=0;
        for(ll i=1;;i++)
        {
            sum+=i;
            if(sum>=x)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
