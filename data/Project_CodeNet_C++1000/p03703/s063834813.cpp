#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 200021
#define int ll
int N,K;
int A[maxn];
int fw[maxn];

void upd(int p,int v){ //update position p by +=v
	for (int i=p; i<=N + 10; i+= (i&(-i))){
		fw[i] += v;
	}
}

int qry(int p){ //query from 1 to p
	int ans = 0;
	for (int i = p; i>0; i -= (i&(-i))){
		ans += fw[i];
	}
	return ans;
}


int32_t main(){
	fast;
	
	cin>>N>>K;
	
	FOR(i,1,N) cin>>A[i];
	
	vpi vect;
	int cursm = A[1];
	
	FOR(i,1,N + 1){
		vect.pb(pi(cursm - K * i,i));
		cursm += A[i];
	}
	
	sort(all(vect),greater<pi>());
	
	
	int ans = 0;
	aFOR(i,vect){
		ans += qry(N + 1) - qry(i.s);
		upd(i.s,1);
	}
	
	cout<<ans;
	
}

