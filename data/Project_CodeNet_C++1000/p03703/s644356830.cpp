#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

const long long MAXN = 2e5+5;
long long arr[MAXN];
long long pref[MAXN];
long long val[MAXN];
long long ans = 0;
int main(){
    indexed_multiset s1;
    long long n,k;
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
        pref[i] = pref[i-1]+arr[i];
        val[i] = pref[i-1]-(k*i);
    }
    val[n+1] = pref[n]-(k*(n+1));
    for(long long i=1;i<=n+1;i++){
        ans+=s1.order_of_key(val[i]+1);
       // cout<<val[i]<<" "<<s1.order_of_key(val[i])<<" "<<ans<<endl;
        s1.insert(val[i]);
    }
    cout<<ans<<endl;
}
