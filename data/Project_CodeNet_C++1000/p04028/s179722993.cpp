#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define inf (ll)1e17
#define modz 1000000007
#define EPS (double)1e-9
#define fi first
#define se second

ll n,dp[5005][5005];
string s;

ll pangkat(ll a, ll b){
	if(b==0) return 1;
	ll tmp = pangkat(a,b/2)%modz;
	tmp = (tmp*tmp)%modz;
	if(b%2==1) tmp = (tmp*a)%modz;
	return tmp;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	cin >> s;
	dp[0][0] = 1;
	for (int i=0;i<=n;i++) {
        for (int j=0;j<=i;j++) {
            dp[i+1][j+1] = (dp[i][j]*2%modz+dp[i+1][j+1])%modz;
            dp[i+1][max(0,j-1)] = (dp[i+1][max(0,j-1)]+dp[i][j])%modz;
        }
    }
    cout << (pangkat(pangkat(2,s.length()),modz-2)*dp[n][s.length()])%modz << endl;
}