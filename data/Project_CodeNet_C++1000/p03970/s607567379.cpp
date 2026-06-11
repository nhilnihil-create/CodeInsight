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

int main(){
	string s;cin>>s;
	int ans = 0;
	string t = "CODEFESTIVAL2016";
	for(int i = 0; i < s.size(); i++) {
		if (s[i] != t[i])ans++;
	}
	cout << ans << endl;
	return 0;
}