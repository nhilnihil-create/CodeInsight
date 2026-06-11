#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second
class coord{
	public:
		int x,y;
};
int main(void) {
	coord s,t;
	cin >> s.x >> s.y >> t.x >> t.y;
	rep(i,(t.x-s.x)) cout << "R";
	rep(i,(t.y-s.y)) cout << "U";
	rep(i,(t.x-s.x)) cout << "L";	
	rep(i,(t.y-s.y)) cout << "D";
	cout << "D";
	rep(i,(t.x-s.x)+1) cout << "R";	
	rep(i,(t.y-s.y)+1) cout << "U";
	cout << "L";
	cout << "U";
	rep(i,(t.x-s.x)+1) cout << "L";	
	rep(i,(t.y-s.y)+1) cout << "D";
	cout << "R";
	cout << endl;
}
