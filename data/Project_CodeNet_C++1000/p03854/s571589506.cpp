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

bool func(string s, int t){
	if(t==s.length()) return true;
	if (s.substr(t,7)=="dreamer") return func(s,t+5) || func(s,t+7);
	if (s.substr(t,6)=="eraser") return func(s,t+6);
	if (s.substr(t,5)=="dream" || s.substr(t,5)=="erase") return func(s,t+5);
	
	else return false;
}

int main(){
	string s;
	cin >> s;
	int i=0;

	
	//cout << i <<"\n";
	if(func(s,0)) cout << "YES";
	else cout << "NO";
	return 0;
}