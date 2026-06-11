#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll k;
ll a[100];
int main(){
	cin >> k;
	ll n = 50;

	REP(i,n) {
		a[i] = n - 1 + (k / n);
	}

	REP(i,k % n) {
		a[i] += n - (k % n) + 1;
	}
	FOR(i,k % n,n) {
		a[i] -= (k % n);
	}
	cout << n << endl;
	REP(i,n) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
