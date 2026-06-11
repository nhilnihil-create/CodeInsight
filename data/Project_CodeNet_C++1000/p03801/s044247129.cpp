#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
#define pb push_back
#define mp make_pair
#define taskname "A"
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n , k;
ii a[maxn];
ll res[maxn];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w  ",stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i].first;a[i].second = i;
    }
    sort(a + 1 , a + n + 1);
    int pre = n;
    for(int i = n ; i >= 1 ; --i){
        pre = min(pre , a[i].second);
        res[pre] += (a[i].first - a[i - 1].first) * (ll)(n - i + 1);
    }
    for(int i = 1 ; i <= n ; ++i)cout << res[i] << '\n';
}