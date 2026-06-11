#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N;
	cin >> N;
	vector<ll> a(3*N+2,0);
	FOR(i,1,3*N+1)cin>>a[i];

	ll red[N*2+1];
	red[0]=0;
	priority_queue<ll, vector<ll>, greater<ll>> rq;
	FOR(i,1,N+1){
		red[i] = red[i-1] + a[i];
		rq.push(a[i]);
	}
	FOR(i,N+1,N*2+1){
		red[i] = red[i-1]+a[i];
		rq.push(a[i]);
		red[i] -= rq.top();
		rq.pop();
	}

	ll blue[N*2+1];
	blue[0]=0;
	REV(a);
	priority_queue<ll> bq;
	FOR(i,1,N+1){
		blue[i] = blue[i-1] + a[i];
		bq.push(a[i]);
	}
	FOR(i,N+1,N*2+1){
		blue[i] = blue[i-1]+a[i];
		bq.push(a[i]);
		blue[i] -= bq.top();
		bq.pop();
	}
	ll ans = -INF;
	FOR(i,N,N*2+1){
		ans = max(ans,red[i] - blue[3*N-i]);
	}
	cout << ans << endl;
}	