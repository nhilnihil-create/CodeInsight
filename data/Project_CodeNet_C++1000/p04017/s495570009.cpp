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
const int logn = 20;
int P[maxn][logn];
int n , L  , q;
ll x[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x[i];
//        x[i] = x[i - 1] + x[i];
    }
    cin >> L >> q;
    for(int i = 1 ; i <= n ; ++i){
        P[i][0] = P[i - 1][0];
        while(P[i][0] <= n && x[P[i][0]] - x[i] <= L)++P[i][0];
        --P[i][0];
//        cout << x[P[i][0] + 1] - x[i] << " ";
//        cout << P[i][0] << "\n";
    }
    for(int j = 1 ; j < logn ; ++j){
        for(int i = 1 ; i <= n ; ++i){
            P[i][j] = P[P[i][j - 1]][j - 1];
//            cout << i << " " << j << " " << P[i][j] << endl;
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        int u , v;cin >> u >> v;
        if(u > v)swap(u , v);
        int res = 0;
        for(int j = logn - 1 ; j >= 0 ; --j){
            if(P[u][j] < v)u = P[u][j] , res += (1 << j);
        }
        cout << res + 1 << '\n';
    }
}
