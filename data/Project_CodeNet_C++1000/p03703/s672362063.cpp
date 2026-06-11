#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<long long , long long >, null_type, less<pair<long long , long long>>, rb_tree_tag,
tree_order_statistics_node_update> ordered_setpair;

const int N = 2e5+5;

const int mod = 1e9 +7;

int n;
int k;
int ar[N];
long long prefix[N];
 ordered_setpair SS;
int main()
{
    cin >> n >> k;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        prefix[i] = (prefix[i - 1] + ar[i]);
    }
    SS.insert(make_pair(0 , 0));
    for(long long i = 1; i <= n; i++){
        //cout << SS.order_of_key(make_pair(prefix[i] - i*k , 1e18)) << "\n";
        ans +=  SS.order_of_key(make_pair(prefix[i] - i*k , 1e18)) ;
        SS.insert({make_pair(prefix[i] - i*k , i)});

    }
    printf("%lld\n" , ans);

    return 0;
}