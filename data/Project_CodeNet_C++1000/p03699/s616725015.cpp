#include<bits/stdc++.h>
// Begin Header {{{
#define all(x) (x).begin(), (x).end()
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
//Function
lli combi(lli n, lli r)
{
	if(r==0 || r==n) return 1;
	else return combi(n-1,r) + combi(n-1,r-1);
}
lli sigma1(lli n){return n*(n+1)/2;}
lli sigma2(lli s, lli n){return sigma1(n) - sigma1(s -1);}
using namespace std;
// }}} End Header

int main()
{
	int n, ans =0, hiki = INF;
	cin >> n;
	vector<int> s(n);
	rep(i,n){
		cin >> s[i];
		ans+=s[i];
	}
	sort(all(s));
	for(const auto& x : s){
		if(x%10 != 0){
			hiki = x;
			break;
		}
	}
	if(hiki == INF) ans =0;
	else if(ans%10== 0){
		ans -= hiki;
	}
	cout << ans << endl;
	return 0;
}
