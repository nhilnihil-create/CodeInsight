#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));


int main(){	
	long long N;
	string s;
	scanf("%lld",&N);
	cin >> s;
	bool sheep[N];
	bool flg = false;
	rep(i, 4) {
		sheep[0] = i%2 == 0;
		sheep[1] = i < 2;
		rep(j, N-2) {
			if (sheep[j+1] && s[j+1] == 'o') sheep[j+2] = sheep[j];
			if (!sheep[j+1] && s[j+1] == 'o') sheep[j+2] = !sheep[j];
			if (sheep[j+1] && s[j+1] == 'x') sheep[j+2] = !sheep[j];
			if (!sheep[j+1] && s[j+1] == 'x') sheep[j+2] = sheep[j];
		}
		if ((sheep[N-1] && s[N-1] == 'o' && sheep[N-2] == sheep[0]) 
			|| (!sheep[N-1] && s[N-1] == 'o' && sheep[N-2] != sheep[0])
			|| (sheep[N-1] && s[N-1] == 'x' && sheep[N-2] != sheep[0])
			|| (!sheep[N-1] && s[N-1] == 'x' && sheep[N-2] == sheep[0])) {
			if ((sheep[0] && s[0] == 'o' && sheep[N-1] == sheep[1]) 
			|| (!sheep[0] && s[0] == 'o' && sheep[N-1] != sheep[1])
			|| (sheep[0] && s[0] == 'x' && sheep[N-1] != sheep[1])
			|| (!sheep[0] && s[0] == 'x' && sheep[N-1] == sheep[1])) {
				flg = true;
				break;
			}
		}
	}
	
	if (flg) {
		rep(i, N) {
			if (sheep[i]) cout << "S"; else cout << "W";
		}
		cout << endl;
	} else {
		cout << "-1" << endl;
	}

	return 0;
}

