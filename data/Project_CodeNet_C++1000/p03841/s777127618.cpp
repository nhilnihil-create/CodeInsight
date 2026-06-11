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

int cnt[505]  , brr[250005];

pair < int , int > arr[505];

int main()
{
    fastio;

    int n;

    cin>>n;

    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }

    sort(arr+1,arr+n+1);
    int cur = 1 , ext = 1 , fin = 1;
    arr[n+1].first = n*n+1;
    arr[n+1].second = n+1;
    for(int i = 1 ; i<=n*n ; i++){
        if(arr[cur].first < i){
            cout<<"No\n";
            return 0;
        }
        else if(arr[cur].first == i){
            if(cnt[arr[cur].second] != arr[cur].second - 1){
                cout<<"No\n";
                return 0;
            }
            brr[i] = arr[cur].second;
            cur++;
        }
        else{
            while(ext <= n && cnt[arr[ext].second] >= arr[ext].second-1) ext++;
            if(ext == n+1){
                while(cnt[arr[fin].second] == n) fin++;
                if(fin>=cur){
                    cout<<"No\n";
                    return 0;
                }
                brr[i] = arr[fin].second;
            }
            else{
                brr[i] = arr[ext].second;
            }
        }

        cnt[brr[i]]++;
    }

    cout<<"Yes\n";

    for(int i = 1 ; i <= n*n ; i++) cout<<brr[i]<<" ";
    cout<<endl;

    return 0;
}
