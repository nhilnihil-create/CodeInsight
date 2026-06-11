#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int mm[100005];
int cnt[100005];

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

// #ifndef ONLINE_JUDGE
//     if(fopen("INPUT.txt","r"))
//     {
//     freopen ("INPUT.txt" , "r" , stdin);
//     freopen ("OUTPUT.txt" , "w" , stdout);
//     }
// #endif  

    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=n;i++)
        cnt[i]=1;
    mm[1]=1;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        cnt[x]--;
        cnt[y]++;
        if(mm[x])
        {
            mm[y]=1;
        }
        if(cnt[x]==0)
            mm[x]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=mm[i];

    cout<<ans;
} 
    
 