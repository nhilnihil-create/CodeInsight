#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) for(int i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<ll, int> P;

int h,w,d;
char s[4]={'R','Y','G','B'};
char c[500][500];

int main(){
	cin.tie(0);
  ios::sync_with_stdio(false);

	cin>>h>>w>>d;
	REP(i,h) {
		REP(j,w) {
			int y=i+j;
			int x=i-j+h+w;
			int color=y/d%2*2 + x/d%2;
			c[i][j]=s[color];
		}
	}

	REP(i,h) {
		REP(j,w) {
			cout<<c[i][j];
		}
		cout<<endl;
	}

	return 0;
}
