#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long ll;

template <class T>
using ordered_set=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        v[i]-=k;
    }
    ll res=0;
    ll sum=0;
    map<ll,int> m;
    ordered_set<pair<ll,int>> s;
    for(int i=0;i<n;i++)
    {
        s.insert({sum,++m[sum]});
        sum+=v[i];
        res+=s.order_of_key({sum,m[sum]+1});
    }
    printf("%lld\n",res);
    return 0;
}
