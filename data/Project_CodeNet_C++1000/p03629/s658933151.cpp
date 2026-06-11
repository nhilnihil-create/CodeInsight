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

const int maxn = 2e5 + 5;
#define next asfopj

int n , dp[maxn] , next[maxn][26];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> s;
    n = s.size();
    fill_n(&next[0][0],maxn*26,n+1);
    for(int i = n - 1 ; i >= 0 ; --i){
        for(int j = 0 ; j < 26 ; ++j){
            if(s[i] == j + 'a')next[i][j] = i;
            else next[i][j] = next[i + 1][j];
        }
    }
    dp[n] = 1;
    for(int i = n - 1 ; i >= 0 ; --i){
        dp[i] = 1e9;
        for(int j = 0 ; j < 26 ; ++j){
            dp[i] = min(dp[i] , dp[next[i][j] + 1] + 1);
        }
    }
    string res = "";
    for(int now = 0 ; now < n + 1 ; ){
        for(int j = 0 ; j < 26 ; ++j){
            if(dp[now] == dp[next[now][j] + 1] + 1){
                res += char(j + 'a');
                now = next[now][j] + 1;
                break;
            }
        }
    }
    cout << res;
}
