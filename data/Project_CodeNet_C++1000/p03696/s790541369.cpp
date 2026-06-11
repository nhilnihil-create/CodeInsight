#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	string s; cin>>s;
	string s2=s;
	string ans=s;
	int a=0,b=0;
	rep(i,0,n){
		if(s[i]==')') continue;
		bool k=true;
		rep(j,i+1,n){
			if(s2[j]==')'){
				k=false;
				s2[j]='!';
				break;
			}
		}
		if(k) a++;
	}
	reverse(all(s));
	s2=s;
	rep(i,0,n){
		if(s[i]=='(') continue;
		bool k=true;
		rep(j,i+1,n){
			if(s2[j]=='('){
				k=false;
				s2[j]='!';
				break;
			}
		}
		if(k) b++;
	}
	//cout<<a<<" "<<b;
	rep(i,0,a) ans.push_back(')');
	reverse(all(ans));
	rep(i,0,b) ans.push_back('(');
	reverse(all(ans));
	cout<<ans;
	return 0;
}