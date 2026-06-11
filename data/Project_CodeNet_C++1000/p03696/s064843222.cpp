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
void solve(){
	vector<char> v;
	int n= s.length();
	v.eb(s[0]);
	for(int i=1;i<n;i++){
		if(s[i]==')' && v.back()=='(') v.pop_back();
		else v.eb(s[i]);
	}
	int i=0;
	while(i<v.size()&& v[i]==')'){
		i++;
	}
	int count=i;
	int count1=v.size()-i;
	string t(count,'(');
	string t1(count1,')');
	cout << t+s+t1;
}
int main(){
	int k;
	cin >> k;
	cin >> s;
	solve();

	return 0;
}