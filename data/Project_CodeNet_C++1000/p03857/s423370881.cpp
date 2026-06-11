#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 201010

int N,K,L,a,b;
int M[MAXN];
int R[MAXN];
vi V[MAXN];
int fw[MAXN];

void update(int x, int v) {
	// cout<<"Up "<<x<<' '<<v<<'\n';
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}
int sum(int x) {
    int res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

int p[MAXN];
int par(int x){return (p[x] == x)?x:p[x] = par(p[x]);}
vpi T;
int out[MAXN];
vi starts;

int main()
{
	cin>>N>>K>>L;
	for (int i=1;i<=N;++i)p[i]=i;
	for (int i=0;i<K;++i){
		cin>>a>>b;
		p[par(a)] = par(b);
	}
	T.pb(-1,-1);
	for (int i=1;i<=N;++i)T.pb(par(i),i);
	sort(ALL(T));
	for (int i=1;i<=N;++i){
		M[T[i].s] = i;
		R[i] = T[i].s;
		if (T[i].f != T[i-1].f)starts.pb(i);
	}
	starts.pb(N+1);

	for (int i=1;i<=N;++i)p[i]=i;
	for (int i=1;i<=L;++i){
		cin>>a>>b;
		a=M[a];
		b=M[b];
		p[par(a)] = par(b);
	}
	for (int i=1;i<=N;++i)V[par(i)].pb(i);
	for (int i=1;i<=N;++i)if(SZ(V[i])){
		for (auto x:V[i])update(x,1);

		for (auto x:V[i]){
			auto t = --ub(ALL(starts), x);
			int st = *t;
			int en = *(++t)-1;
			// cout<<st<<' '<<en<<'\n';
			int ans = sum(en) - sum(st-1);
			out[R[x]] = ans;
		}

		for (auto x:V[i])update(x,-1);
	}
	for(int i=1;i<=N;++i)cout<<out[i]<<' ';
}