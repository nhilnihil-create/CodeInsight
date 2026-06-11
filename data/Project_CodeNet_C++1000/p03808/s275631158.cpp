//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)1e8 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX_X ((ll)1e5 + 2)
#define pi (2.0*acos(0))
#define M ((int)1e6 + 7)
#define MOD ((int)1e9 + 7)
#define NN ((int)1e6 + 7)
#define N ((int)1e5 + 7)
#define eps (0)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 29
#define endl "\n"
#define mp make_pair
#define BUCK 105
#define LEF (idx<<1)
#define RIG ((idx<<1)|1)
//#define int ll


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/




typedef tree < pair < ll, pair < ll, ll > >,  null_type,  less < pair < ll, pair < ll, ll > > >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).

ll arr[N];

void ses()
{
    cout<<"NO\n";
    exit(0);
}

int main()
{
    fastio;
    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    ll con = 1ll*n*(n+1)/2;
    if(sum % con != 0) ses();
    int tot = sum/con;
    for(int i = 1 ; i<=n ; i++){
        arr[i] -= 1ll*i*tot;
    }
    ll cnt = 0;
    for(int i = 1 ; i < n ; i++){
        ll tmp = arr[i] - arr[i+1];
        if(tmp < 0 || tmp%n != 0) ses();
        cnt += tmp/n;
    }
    if(cnt<=tot) cout<<"YES\n";
    else ses();
    return 0;
}
