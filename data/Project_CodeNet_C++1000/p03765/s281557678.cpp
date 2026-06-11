#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef pair<ll,ld> pd;
typedef pair<ld,ll> pdi;

typedef vector <pd> vpi;
typedef pair<pi,ll> pii;
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
#define maxn 100001

string S,T;
int q;

int SsumsA[maxn],SsumsB[maxn],TsumsA[maxn],TsumsB[maxn];

int main(){
	fast;
	
	cin>>S>>T>>q;
	
	FOR(i,1,S.size()){
		if (S[i-1] == 'A'){
			SsumsA[i] = SsumsA[i-1] + 1;
			SsumsB[i] = SsumsB[i-1];
		}else{
			SsumsA[i] = SsumsA[i-1] ;
			SsumsB[i] = SsumsB[i-1] + 1;
		}
	}
	
	FOR(i,1,T.size()){
		if (T[i-1] == 'A'){
			TsumsA[i] = TsumsA[i-1] + 1;
			TsumsB[i] = TsumsB[i-1];
		}else{
			TsumsA[i] = TsumsA[i-1] ;
			TsumsB[i] = TsumsB[i-1] + 1;
		}
	}
	
	FOR(i,0,q-1){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		int AsumsS = SsumsA[b] - SsumsA[a-1], BsumsS = SsumsB[b] - SsumsB[a-1];
		int AsumsT = TsumsA[d] - TsumsA[c-1], BsumsT = TsumsB[d] - TsumsB[c-1];
		
		int Ssum = AsumsS + 2 * BsumsS;
		int Tsum = AsumsT + 2 * BsumsT;
		
		if (Ssum % 3 == Tsum % 3) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
