#include<bits/stdc++.h>
// Begin Header {{{
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<lli>>;
using P = pair<int, int>;
// }}} End Header

int main(){
	string s;
	cin >> s;
	if(s[0] == '9' || s[1] == '9') puts("Yes");
	else puts("No");
	return 0;
}