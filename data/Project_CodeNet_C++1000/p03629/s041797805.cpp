#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std ;
using namespace __gnu_pbds;

template <typename T> // *s.find_by_order(0), s.order_of_key(2) ;
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define reMin(a, b) a = min(a, b)
#define reMax(a, b) a = max(a, b)

#define lint long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second

typedef vector < int > vi ;
typedef pair < int, int > pii ;

const int N = 2e5 + 2 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;

int nearest[N][26] ;
bool visited[N] ;
int backLink[N] ;

string s ;
int n ;
int latest[26] ;
queue < int > q ;

int main()
{
    fastio; cin >> s ; s = '#' + s ; n = s.length();
    for(int i = 0; i <= n; i++) for(int j = 0; j < 26; j++) nearest[i][j] = -1 ;
    SET(latest, -1);
    for(int i = n; i >= 0; i--)
    {
        for(int j = 0; j < 26; j++) nearest[i][j] = latest[j] ;
        if(i) latest[s[i] - 'a'] = i ;
    }
    SET(visited, 0); SET(backLink, 0);
    q.push(0); string ans = "" ; bool found = 0 ;
    while(!q.empty())
    {
        int cur = q.front(); q.pop(); visited[cur] = 1 ;
        for(int j = 0; j < 26; j++)
        {
            int nxt = nearest[cur][j];
            if(nxt == -1)
            {
                ans = ('a' + j);
                // cout << ans << endl ;
                if(cur) ans = s[cur] + ans ;
                while(backLink[cur]) {
                    cur = backLink[cur] ;
                    ans = s[cur] + ans ;
                }
                found = 1 ;
                break ;
            }
            else if(!visited[nxt]) {
                q.push(nxt);
                backLink[nxt] = cur ;
                visited[nxt] = 1 ;
            }
        }
        if(found) break ;
    }
    cout << ans ;
}

