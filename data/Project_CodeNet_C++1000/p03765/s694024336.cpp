#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
//#define F first
//#define S second

struct info{
	int n;
	vector<string> tree;

	info(string s) {
		n = s.size();
		tree = vector<string>(4*n);
		string dummy = init(1,0,n-1,s);
	}

	string init(int node, int l, int r, string& s) {
		if(l == r) {
			return tree[node] = s[l];
		}
		int m = (l+r)/2;
		string t = init(node*2, l, m, s) + init(node*2+1, m+1, r, s);
		return tree[node] = mycal(t);
	}

	string query(int node, int s, int e, int l, int r) {
		if(r < s || e < l) 
			return "";
		if(l <= s && e <= r) 
			return tree[node];
		int m = (s+e)/2;
		string t = query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
		return mycal(t);
	}

	string query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}

	string mycal(string t) {
		int n = sz(t);
		
		if(n <= 1) return t;
		
		if(n == 2) {
			if(t[0] != t[1]) return "";
			if(t[0] == t[1]) {
				return (t[0] == 'A' ? "B" : "A");
			}
		}

		rep(i,0,n-1) {
			if(t[i] != t[i+1]) {
				string ret = "";
				if(i>0) 
					ret += t.substr(0,i);
				if(i+2<n) 
					ret += t.substr(i+2);
				return ret;
			}
		}

		rep(i,0,n-2) {
			if(t[i] == t[i+1] && t[i+1] == t[i+2]) {
				string ret = "";
				if(i > 0) 
					ret += t.substr(0,i);
				if(i+3 < n) 
					ret += t.substr(i+3);
				return ret;
			}
	}

	return t;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("in.txt", "r", stdin);
	string S, T;

	cin >> S;
	cin >> T;

	int n = sz(S);
	int m = sz(T);

	info myS(S);
	info myT(T);
	int q;
	cin >> q;
	rep(i,0,q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		string ss = myS.query(a,b);
		string tt = myT.query(c,d);
		if(ss == tt) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
