#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 gen_rand_int(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 gen_rand_ll(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}

int a[305][305];
int pos[305][305];

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    string a;
    cin>>a;
    int n=a.length();
    int mm[26]={0};
    for(int i=0;i<n;i++)
    {
        mm[a[i]-'a']++;
    }
    int ans=0;
    int tot=n;
    for(int i=0;i<n;i++)
    {
        tot--;
        mm[a[i]-'a']--;
        int z=mm[a[i]-'a'];
        ans+=tot-z;
    }
    cout<<ans+1;

} 
    
