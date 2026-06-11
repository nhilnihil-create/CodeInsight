#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int N;
	string s, t;
	
	cin >> N >> s >> t;
	int d = N;
	REP(i, 0, N){
		string l = s.substr(i, d);
		string r = t.substr(0, d);
		if(l == r){
			cout << i + (int)l.size() + N-(int)l.size();
			exit(0);
		}
		--d;
	}
	cout << 2*N;
}
