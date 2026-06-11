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

    int n,l;
    cin>>n>>l;

    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=1;i<n;i++)
    {
        if(a[i]+a[i-1]>=l)
        {
            vector<int>ans;
            for(int j=1;j<i;j++)
                ans.push_back(j);
            for(int j=n-1;j>i;j--)
                ans.push_back(j);
            ans.push_back(i);
            cout<<"Possible\n";
            for(auto j:ans)
                cout<<j<<'\n';
            return 0;
        }
    }
    cout<<"Impossible";
} 
    
 
