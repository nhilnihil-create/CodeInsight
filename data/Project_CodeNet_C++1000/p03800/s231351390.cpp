#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod = 1000000007;		


int n;
string s;
string t;

void solve(int n) {
	FOR(i, 1, n) {
		if (s[i] == 'o') {
			if (t[i] == 'S') {
				t += t[i - 1];
			}
			else {
				if (t[i - 1] == 'W')t += 'S';
				else t += 'W';
			}
		}
		else {
			if (t[i] == 'W')t += t[i - 1];
			else {
				if (t[i - 1] == 'W')t += 'S';
				else t += 'W';
			}
		}
	}
}

bool check(string u) {
	if (u[0] != u[u.size() - 1])return false;
	if (s[0] == 'o') {
		if (u[0] == 'S') {
			if (u[1] == 'S') {
				if (u[u.size() - 2] == 'S')return true;
				else return false;
			}
			else {
				if (u[u.size() - 2] == 'W')return true;
				else return false;
			}
		}
		else {
			if (u[1] == 'W') {
				if (u[u.size() - 2] == 'S')return true;
				else return false;
			}
			else {
				if (u[u.size() - 2] == 'W')return true;
				return false;
			}
		}
	}
	else{
		if (u[0] == 'S') {
			if (u[1] == 'S') {
				if (u[u.size() - 2] == 'W')return true;
				else return false;
			}
			else {
				if (u[u.size() - 2] == 'S')return true;
				else return false;
			}
		}
		else {
			if (u[1] == 'W') {
				if (u[u.size() - 2] == 'W')return true;
				else return false;
			}
			else {
				if (u[u.size() - 2] == 'S')return true;
				return false;
			}
		}
	}
}

int main() {


	cin >> n;

	cin >> s;

	t = "SS";
	solve(n);
	if (check(t)) {
		cout << t.substr(0, n) << endl;
		return 0;
	}
	t = "SW";
	solve(n);
	if (check(t)) {
		cout << t.substr(0, n) << endl;
		return 0;
	}
	t = "WS";
	solve(n);
	if (check(t)) {
		cout << t.substr(0, n) << endl;
		return 0;
	}
	t = "WW";
	solve(n);
	if (check(t)) {
		cout << t.substr(0, n) << endl;
		return 0;
	}

	cout << -1 << endl;

	return 0;
}
