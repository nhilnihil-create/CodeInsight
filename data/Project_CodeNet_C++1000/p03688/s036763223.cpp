#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((ll)(2e9))
#define pi (acos(-1))
#define M ((ll)(998244353))
#define NN ((ll)(1e4+2))
#define N ((ll)(1e5 + 5))
#define eps 0
#define log 20


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
/// typedef tree < pair < ll,ll >,  null_type,  less < pair < ll,ll > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).

int arr[N];


int main()
{
    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    if(arr[0]==arr[n-1] && arr[0]==n-1){
        cout<<"Yes\n";
        return 0;
    }

    if(arr[0]!=arr[n-1] && arr[0]+1!=arr[n-1]){
        cout<<"No\n";
        return 0;
    }

    int col = arr[n-1];
    int rem;
    if(arr[0]!=arr[n-1]){

        for(int i = 0; ; i++){
            if(arr[i]==arr[n-1]){
                col -= i;
                rem = n-i;
                break;
            }
        }
    }
    else rem = n;

    if(col>0 && col*2<=rem){
        cout<<"Yes\n";

    }
    else{
        cout<<"No\n";

    }

    return 0;


}
