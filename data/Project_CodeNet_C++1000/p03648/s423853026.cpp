/*input
500000000000000000
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 500
#define INF 0x3f3f3f3f

int n = 50 , x[MAX];
int solve(){
    int big = 0;
    REP(i , 1 , n + 1) big = max(big , x[i]);
    if(big < n) return 0;
    REP(i , 1 , n + 1) if(x[i] == big){
        REP(j , 1 , n + 1) x[j] ++;
        x[i] += -1 - n;
        return 1;
    }
}
int k;
int32_t main(){
    IOS;
    cin >> k;
    int tmp = (k / 50) + 1;
    int base = n - 1 + tmp;
    REP(i , 1 , n + 1) x[i] = base + 1 - i;
    // REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
    // DBGG("tmp * 50 = " , tmp * 50);
    RREP(i , tmp * 50 , k + 1) solve();
    // cout << "answer = " << endl;
    cout << n << endl;
    REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
    // cout << "---" << endl;
    // int times = 0;
    // do{
    //     times ++;
    //     REP(i , 1 , n + 1) cout << x[i] << " "; cout << endl;
    // } while(solve());
    // DBGG("times = " , times);
    return 0;
}