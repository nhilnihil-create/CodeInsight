#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	string s; cin>>s;
	while(true){
		if(s.empty())break;
		string a,b,c;
		a.resize(5);
		b.resize(6);
		c.resize(7);
		int n=s.size();
		if(5>n){
			cout<<"NO"<<endl;
			return 0;
		}
		rep(i,0,5){
			a[i]=s[n-1-i];
		}
		reverse(all(a));
		if(a=="dream" || a=="erase"){
			rep(i,0,5)s.pop_back();
			continue;
		}
		if(n>5){
			rep(i,0,6){
				b[i]=s[n-1-i];
			}
		}
		reverse(all(b));
		if(b=="eraser"){
			rep(i,0,6)s.pop_back();
			continue;
		}
		if(n>6){
			rep(i,0,7){
				c[i]=s[n-1-i];
			}
		}
		reverse(all(c));
		if(c=="dreamer"){
			rep(i,0,7)s.pop_back();
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	
	
	return 0;
}