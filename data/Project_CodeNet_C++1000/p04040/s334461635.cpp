#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) max_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))


#define SIZE 200005
#define MOD 1000000007
 
typedef pair <int,int> P;
 
ll inv[SIZE], fac[SIZE], finv[SIZE];
void make(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2; i<SIZE; i++)
	{
		inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
		fac[i] = fac[i-1] * (ll) i % MOD;
		finv[i] = finv[i-1] * inv[i] % MOD;
	}
    return ;
}
ll comb(int a,int b){
	if(a < b) return 0;
	return fac[a] * (finv[b] * finv[a-b] % MOD) % MOD;
}



int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int H, W, A, B; cin >> H >> W >> A >> B; H--; W--;
    make();
    ll all = comb(W+H, W);
    rep(i,B) {
		ll part = comb( H - A + i,  i );
		ll part2 = comb( W - i + A - 1, A - 1 );
		all -= part * part2 % MOD;
		if(all < 0) all += MOD;
	}


    cout << all << endl;
    
}