/*  
    Beyond the door
    There's peace I'm sure
    And I know there'll be no more
    Tears in heaven
    _________________________
    _________________________
    792 Hours of Solitude
    Quarantine_Day : 33
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int       ll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef pair<int, int>      pii;

#define pb(n)           push_back(n)
#define GSORT(v)        sort(v.begin(), v.end(), greater<int>())
#define SORT(v)         sort(v.begin(), v.end());
#define REV(v)          reverse(v.begin(), v.end());
#define db(a)           cout<<#a<<" = "<<a<<endl;
#define FIN             freopen("in.txt","r",stdin);
#define FOUT            freopen("out.txt","w",stdout);
#define REP(i,n)        for(int i = (int)(0); i < (int)(n); i++)
#define FOR(i, a, b)    for(int i = (int)a; i <= (int)b; i++)    

#define MAX 55

ll n;
double a;
vl v(MAX);
ll dp[MAX][MAX][2500];

ll go(ll idx, ll taken, ll sum){
	if(idx >= n){
		if(((double)sum / (double)taken) == a) return 1;
		else return 0;
	}
	if(dp[idx][taken][sum] != -1) return dp[idx][taken][sum];

	return  dp[idx][taken][sum] = go(idx + 1, taken + 1, sum + v[idx]) + go(idx + 1, taken, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>a;
	REP(i, n) cin>>v[i];

	memset(dp, -1, sizeof(dp));
	cout<<go(0, 0, 0)<<"\n";
	return 0;
}
