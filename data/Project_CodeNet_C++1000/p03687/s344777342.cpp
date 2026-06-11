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

bool isOK(vi &s, int n){
	rep(i,n-1) if(s[i]!=s[i+1]) return false;
	return true;
}

int main(void) {
	string s; cin >> s;
	vi a(s.size());
	rep(i,s.size()) a[i] = s[i] - 'a';
	int ans = INF;
//	rep(j,s.size()) cout << a[j] << " ";
//	cout << endl;	
	rep(i,26){
		int x = i;
		int n = a.size();
		vi b = a;
		int cnt = 0;
		while(!isOK(b,n)){
			n--;
			vi c = b;
			rep(j,n){
				if(c[j]==x) b[j] = c[j];
				else if(c[j+1]==x) b[j] = c[j+1];
				else b[j] = c[j];
			}
//			rep(j,n) cout << b[j] << " ";
//			cout << endl;
			cnt++;
		}
		ans = min(ans,cnt);
	}
	cout << ans << endl;
}
