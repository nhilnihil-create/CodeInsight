#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

ll jud(ll x, ll y, char z){//xは前の値、yは前のox
	if (x==0 && y==0 && z=='o') return 0;
	else if (x==0 && y==1 && z=='o') return 1;
	else if (x==1 && y==0 && z=='o') return 1;
	else if (x==1 && y==1 && z=='o') return 0;
	else if (x==0 && y==0 && z=='x') return 1;
	else if (x==0 && y==1 && z=='x') return 0;
	else if (x==1 && y==0 && z=='x') return 0;
	else return 1;
}

int main(){
	ll n; cin >> n;
	string s; cin >> s;
	vector<ll> ansl1(n+1,2);
	vector<ll> ansl2(n+1,2);
	vector<ll> ansl3(n+1,2);
	vector<ll> ansl4(n+1,2);
	ansl1[0]=0;
	ansl2[0]=0;
	ansl3[0]=1;
	ansl4[0]=1;
	ansl1[1]=0;
	ansl2[1]=1;
	ansl3[1]=0;
	ansl4[1]=1;

	FOR(i,2,n){
		ansl1[i]=jud(ansl1[i-2],ansl1[i-1],s[i-1]);
		ansl2[i]=jud(ansl2[i-2],ansl2[i-1],s[i-1]);
		ansl3[i]=jud(ansl3[i-2],ansl3[i-1],s[i-1]);
		ansl4[i]=jud(ansl4[i-2],ansl4[i-1],s[i-1]);
	}
/*	REP(i,n){
		cout << ansl1[i];
	}
	cout << endl;
	REP(i,n){
		cout << ansl2[i];
	}
	cout << endl;
	REP(i,n){
		cout << ansl3[i];
	}
	cout << endl;
	REP(i,n){
		cout << ansl4[i];
	}
	cout << endl;
*/


	if (s[0]=='o'){
		if (ansl1[n-1]==0 && ansl1[n]==ansl1[0]){
			REP(i,n){
				if (ansl1[i]==0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else if (ansl2[n-1]==1 && ansl2[n]==ansl2[0]){
			REP(i,n){
				if (ansl2[i]==0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else if (ansl3[n-1]==1 && ansl3[n]==ansl3[0]){
			REP(i,n){
				if (ansl3[i]==0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else if (ansl4[n-1]==0 && ansl4[n]==ansl4[0]){
			REP(i,n){
				if (ansl4[i]==0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	else{
		if (ansl1[n-1]==1){
			REP(i,n){
				if (ansl1[i]==0 && ansl1[n]==ansl1[0]) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else if (ansl2[n-1]==0 && ansl2[n]==ansl2[0]){
			REP(i,n){
				if (ansl2[i]==0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else if (ansl3[n-1]==0 && ansl3[n]==ansl3[0]){
			REP(i,n){
				if (ansl3[i]==0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else if (ansl4[n-1]==1 && ansl4[n]==ansl4[0]){
			REP(i,n){
				if (ansl4[i]==0) cout << 'S';
				else cout << 'W';
			}
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}