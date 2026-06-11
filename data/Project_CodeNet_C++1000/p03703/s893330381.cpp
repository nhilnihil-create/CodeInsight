#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//1000000000000223
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
indexed_set st ;
ll n , a[200009] , k , ans;
int main()
{
    IO
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i] , a[i]+=a[i-1];
    st.insert(0);
    for(int i=1;i<=n;i++)
    {
        ll cur=a[i]-k*i;
        ans+=st.order_of_key(cur+1);
        st.insert(cur);
    }
    cout<<ans;
    return 0;
}
