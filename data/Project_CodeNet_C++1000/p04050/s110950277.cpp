#include <bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
	int i, n, m, t;
	scanf("%d%d", &n, &m);
	vi o, e, A, B;
	for(i=0; i<m; i++) {
		scanf("%d", &t);
		if(t%2) o.pb(t);
		else e.pb(t);
	}
	if(sz(o)>2) {
		printf("Impossible\n");
		return 0;
	}

	if(sz(o)==0) {
		B.pb(1);
		for(i=0; i<m-1; i++) B.pb(e[i]);
		B.pb(e[m-1]-1);
		A=e;
	}
	else if(sz(o)==1) {
		B.pb(1);
		for(i=0; i<m-1; i++) B.pb(e[i]);
		if(o[0]>1) B.pb(o[0]-1);
		A=e;
		A.pb(o[0]);
	}
	else {
		B.pb(o[0]+1);
		for(i=0; i<m-2; i++) B.pb(e[i]);
		if(o[1]>1) B.pb(o[1]-1);
		A.pb(o[0]);
		for(int t:e) A.pb(t);
		A.pb(o[1]);
	}

	for(i=0; i<m; i++) printf(i==m-1? "%d\n":"%d ", A[i]);
	printf("%d\n", sz(B));
	for(i=0; i<sz(B); i++) printf(i==sz(B)-1? "%d\n":"%d ", B[i]);
   	return 0;
}