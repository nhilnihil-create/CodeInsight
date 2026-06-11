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

int main(void) {
	string s; cin >> s;
	int n = s.size();
	int k; cin >> k;
	vi a(n);
	rep(i,n) a[i] = s[i] - 'a';
	vi add(n);
	rep(i,n) add[i] = (26-a[i])%26;
	rep(i,n){
		if(k<add[i])continue;
		a[i] += add[i];
		a[i] %= 26;
		k -= add[i];
	}
 	
	for(int i=n-1; i>=0; i--){
		if(a[i]==0)continue;
		a[i] += k;
		a[i] %= 26;
		k = 0;
		break;
	}
	if(k>0){
		a[n-1] += k;
		a[n-1] %= 26;
		k = 0;
	}
	
	rep(i,n) printf("%c",'a'+a[i]);
	cout << endl;
}


