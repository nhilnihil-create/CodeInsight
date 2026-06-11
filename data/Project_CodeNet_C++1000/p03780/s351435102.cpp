/*input
3 6
1 4 3
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , k , x[MAX] , pre[MAX] , all = 0;
bitset<MAX> fr[MAX] , ba[MAX];
int query(int ql , int qr){
	if(qr < 0) return 0;
	if(ql <= 0) return 1;
	ql = max(ql , 1LL);
	return pre[qr] - pre[ql - 1] > 0;
}
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i] , all += x[i];
	if(all < k) return cout << n << endl , 0;
	fr[0][0] = ba[n + 1][0] = 1;
	REP(i , 1 , n + 1) fr[i] = fr[i - 1] | (fr[i - 1] << x[i]);
	RREP(i , n , 1)    ba[i] = ba[i + 1] | (ba[i + 1] << x[i]);
	pre[0] = 1;
	int ans = 0;
	REP(i , 1 , n + 1){
		int ql = k - x[i] , qr = k - 1 , ok = 1;
		REP(j , 1 , k + 1) pre[j] = pre[j - 1] + ba[i + 1][j];
		REP(j , 0 , k + 1){
			if(fr[i - 1][j] && query(ql - j , qr - j)) ok = 0;
		}
		// if(ok == 1) cout << i << endl;
		ans += ok;
	}
	cout << ans << endl;
    return 0;
}