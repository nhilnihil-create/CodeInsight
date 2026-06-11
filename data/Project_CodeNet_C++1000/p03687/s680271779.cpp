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
string copy(const string s){return s;}

int main(){
	string s;cin>>s;
	bool q = true;
	for(int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]){continue;}
		else{q = false;}
	}
	if (q){
		cout << 0 << endl;
		return 0;
	}
	int res = INF;
	for(int i = 0; i < 26; i++) {
		char c = 'a' + i;
		int ans = 0;
		string s1 = copy(s);
		while(1){
			bool flag = false;
			string tmp = "";
			for(int i = 1; i < s1.size(); i++) {
				if ((s1[i] == c) || (s1[i - 1] == c)){
					tmp += c;
				}
				else{
					flag = true;
					tmp += '*';
				}
			}
			ans++;

			if (flag){
				s1 = tmp;
			}
			else{
				break;
			}
		}
		res = min(res,ans);
	}
	
	cout << res << endl;
	return 0;
}