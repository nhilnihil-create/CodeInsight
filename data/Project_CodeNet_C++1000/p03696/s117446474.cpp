#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int s_int(string s){
	return atoi(s.c_str());
}
int main(){
	cout << fixed << setprecision(10);
	int r = 0, l = 0;
	int n;
	string s;
	cin >> n >> s;
	int now = 0;
	rep(i,n){
		if(s[i]=='('){
			now++;
		}else{
			if(now > 0) now--;
			else if(now <= 0){
				l++;
			}
		}
	}
	rep(i,l) cout << "(";
	cout << s;
	rep(i,now) cout << ")";
	cout << endl;
	return 0;
}