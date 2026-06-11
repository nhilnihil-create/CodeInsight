/*input
0 0 10 0 0 0 0
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
#define MAX 
#define INF 0x3f3f3f3f

int i , o , t , j , l , s , z , ans;
int32_t main(){
    IOS;
    cin >> i >> o >> t >> j >> l >> s >> z;
    ans = o * 2 , o = 0;
    int v1 = (i / 2 * 4) + (j / 2 * 4) + (l / 2 * 4);
    int v2 = -1;
    if(i && j && l){
        i -- , j -- , l --;
        v2 = 6 + (i / 2 * 4) + (j / 2 * 4) + (l / 2 * 4);
    }
    cout << max(v1 + ans , v2 + ans) / 2 << endl;
    return 0;
}