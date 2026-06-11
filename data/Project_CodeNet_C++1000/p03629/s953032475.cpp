/*input
frqnvhydscshfcgdemurlfrutcpzhopfotpifgepnqjxupnskapziurswqazdwnwbgdhyktfyhqqxpoidfhjdakoxraiedxskywuepzfniuyskxiyjpjlxuqnfgmnjcvtlpnclfkpervxmdbvrbrdn
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

string s;
int nxt[MAX] , dp[MAX];
PII from[MAX];
int32_t main(){
    IOS;
    cin >> s;
    reverse(ALL(s)) , s = " " + s;
    REP(i , 0 , 26) nxt[i] = 0;
    REP(i , 1 , s.size()) dp[i] = INF;
    REP(i , 1 , s.size()){
        REP(j , 0 , 26){
            if(dp[nxt[j]] + 1 < dp[i]){
                dp[i] = min(dp[i] , dp[nxt[j]] + 1);
                from[i] = mp(nxt[j] , j);
            }
        }
        nxt[s[i] - 'a'] = i;
    }
    int sml = INF , id;
    RREP(i , 25 , 0){
        if(dp[nxt[i]] <= sml) sml = dp[nxt[i]] , id = i;
    }
    cout << char('a' + id);
    id = nxt[id];
    while(id != 0){
        cout << char('a' + from[id].B);
        id = from[id].A;
    }cout << endl;
    return 0;
}