#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i=0; i<(long long)(n); i++)
#define REP(i, k, n) for(long long i=(long long)(k); i<(long long)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define PQ(T) priority_queue<T>
#define PQS(T) priority_queue<T, vector<T>, greater<T> >
#define deci cout << fixed << setprecision(15);
typedef long long ll;
const ll inf = 1020304050607080910;
const int mod = 1000000007;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
template<class T> bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
ll gcd(ll x,ll y){if(x>y)swap(x, y);while(x!=0){y%=x;swap(x, y);}return y;}
ll mpow(ll x,ll r){if(r==0)return 1;if(r%2==1){return x*mpow(x,r-1)%mod;}else{ll aa=mpow(x,r/2);return aa*aa%mod;}}

int N, A[100000];

bool solve(void){
	if(N==1) return ((A[0]%2)?false:true);
	int gu = 0, odd;
	rep(i, N){
		if(A[i]%2==0) gu++;
		else odd = i;
	}
	if(gu%2==1 && N>gu) return true;
	if(gu%2==0 && N-gu>1) return false;
	if(A[odd] == 1) return false;
	A[odd]--;
	int g = A[0];
	rep(i, N-1) g = gcd(g, A[i+1]);
	rep(i, N) A[i] /= g;
	return (!solve());
}

int main(){
	cin >> N;
	rep(i, N) cin >> A[i];
	cout << (solve()?"First":"Second") << endl;
	return 0;
}
