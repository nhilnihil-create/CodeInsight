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
	string s;cin >> s;
	int l,r;
	bool flag = false;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] == s[i+1]){
			flag = true;
			l = i;
			r = i+ 1;
			break;
		}
		else if(s[i] == s[i + 2]){
			flag = true;
			l = i;
			r = i+2;
		}
	}
	if(flag){
		cout << l+1 << ' ' << r+1 << endl;
	}
	else{
		cout << -1 << ' ' << -1 << endl;
	}
	return 0;
}