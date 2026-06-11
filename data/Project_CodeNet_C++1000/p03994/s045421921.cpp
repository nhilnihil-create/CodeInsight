#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
string s;
ll k;
ll size;

string func(ll i, ll k){
	if(k==0) return s;
	if(i==size-1){
		ll j=k%26;
		if(j > 'z'-s[i] && s[i] !='a'){
			j-='z'-s[i]+1;
			
			s[i]='a';
			s[i]+=j;
			return s;
		}
		else {
			s[i]+=j;
			return s;
		}
	}
	else if(k>'z'-s[i] && s[i]!='a'){
		
		k-=(ll)('z'-s[i]+1);
		s[i]='a';
		i++;
		return func(i,k);
	}
	else {
		i++;
		return func(i,k);
	} 
		
}

void solve(){
	ll i=0;
	size=s.length();
	cout << func(i,k);
}

int main(){
	cin >> s >> k;
	solve();
	return 0;
}