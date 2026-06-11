//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)1e6 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX_X ((ll)1e5 + 2)
#define pi (2.0*acos(0))
#define M ((int)1e6 + 7)
#define MOD ((int)1e9 + 7)
#define NN ((int)1e6 + 7)
#define N ((int)2e5 + 7)
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

int cnt[105];

int main()
{
    fastio;

    int n;

    cin>>n;
    int mxx = 0 , mnn = n;
    for(int i = 1 ; i<=n ; i++){
        int arr;
        cin>>arr;
        mxx = max(mxx,arr);
        mnn = min(mnn,arr);
        cnt[arr]++;
    }

    bool ans = 1;

    if(mnn != (mxx+1)/2) ans = 0;
    else{
        if(mxx&1){
            if(cnt[mnn] != 2) ans = 0;
        }
        else{
            if(cnt[mnn] != 1) ans = 0;
        }

        for(int i = mnn + 1 ; i<=mxx; i++) if(cnt[i] < 2) ans = 0;
    }

    if(ans) cout<<"Possible\n";
    else cout<<"Impossible\n";

    return 0;
}
