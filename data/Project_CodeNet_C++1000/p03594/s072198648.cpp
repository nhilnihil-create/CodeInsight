#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

const int N = 555;

char ss[N];
char s[N][N];

void fill(int n, int m, int d, int x, int y, char c) {
	//if (x>=0 && y>=0 && x<n && y<m) s[x][y]=c;
	//return;
	for (int i=1-d; i<d; i++) {
		int lo = 1-d+abs(i), hi = d-abs(i);
		for (int j = lo; j <= hi; j++) if (x+i>=0 && x+i<n && y+j>=0 && y+j<m) s[x+i][y+j]=c;
	}
}

int main() {
	int n,m,d;
	scanf("%d%d%d", &n, &m, &d);
	if (d%2==1) {
		FOR(i,n) {
			FOR(j,m) ss[j] = "RY"[(i+j)%2];
			printf("%s\n", ss);
		}
		return 0;
	}
	d /= 2;
	FOR(i,n) FOR(j,m) s[i][j]=' ';
	for (int I = -2*d; I < n+2*d; I += 2*d) for (int J = -4*d; J < m+4*d; J += 4*d) {
		int ff=I/(2*d)%2;
		fill(n,m,d,I,J,"RY"[ff]);
		fill(n,m,d,I+d,J+d,"GB"[ff]);
		fill(n,m,d,I,J+2*d,"YR"[ff]);
		fill(n,m,d,I+d,J+3*d,"BG"[ff]);
	}
	FOR(i,n) {
		printf("%s\n", s[i]);
	}
	return 0;
}
