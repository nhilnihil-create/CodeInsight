//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)3e18 + 7)
#define MAX_X ((ll)1e5 + 2)
#define pi (2.0*acos(0))
#define M ((int)1e6 + 7)
#define MOD ((int)1e9 + 7)
#define NN ((int)3e6 + 7)
#define N ((int)1e5 + 5)
#define eps (0)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 29
#define endl "\n"
#define mp make_pair
#define BUCK 105
#define RIG ((idx<<1)|1)
#define LEF (idx<<1)
//#define int ll


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/




typedef tree < int,  null_type,  less < int >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).


int arr[N];


int main()
{
    fastio;
    int n ;
    cin>>n;
    map < int , bool > pos;
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
        pos[arr[i]] = i&1;
    }
    sort(arr+1,arr+n+1);
    int ans = 0;
    for(int i = 1 ; i<=n ; i++){
        bool flag = pos[arr[i]];
        if(flag != (i&1)) ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}