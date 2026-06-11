#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int a,b,c;cin>>a>>b>>c;
	int ans = 0;

	while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
		int a2 = a;
		int b2 = b;
		int c2 = c;
		vector<int> v = {a2,b2,c2};
		a = (b2/2 + c2/2 );
		b = (a2/2 + c2/2 );
		c = (b2/2 + a2/2 );
		vector<int> v2 = {a,b,c};
		sort(ALL(v));
		sort(ALL(v2));
		ans ++;
		for(int i = 0; i < 3; i++) {
			if (v[i] != v2[i])break;
			if (i == 2){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}