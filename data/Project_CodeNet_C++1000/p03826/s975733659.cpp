#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
	llint a,b,c,d;
	cin >> a >> b >> c >> d;
	llint m1=a*b;
	llint m2=c*d;
	cout << max(m1,m2) << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
