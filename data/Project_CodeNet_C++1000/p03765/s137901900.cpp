#include<bits/stdc++.h>

using namespace std;

struct Eins {
	vector<int> st;
	int n;
	Eins(int n = 0) : n(n) {
		st.resize(n << 2 | 1);
	}
	void build(int id,int l,int r,string&s) {
		if (l == r) {
			st[id] = (s[l-1] == 'B') + 1;
			return ;
		}
		int mid = l + r >> 1;
		build(id << 1,l,mid,s);
		build(id << 1|1,mid+1,r,s);
		st[id] = st[id << 1] + st[id << 1|1];
	}
	int get(int id,int l,int r,int L,int R) {
		if (l > R || r < L) return 0;
		if (L <= l && r <= R) return st[id];
		int mid = l + r >> 1;
		return get(id << 1,l,mid,L,R) + get(id << 1|1,mid+1,r,L,R);
	}
	int get(int L,int R) {
		return get(1,1,n,L,R);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s,t;
	cin >> s >> t;
	Eins T1((int)s.size());
	Eins T2((int)t.size());
	T1.build(1,1,(int)s.size(),s);
	T2.build(1,1,(int)t.size(),t);
	int q;
	cin >> q;
	while (q--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if (T1.get(a,b) % 3 == T2.get(c,d) % 3) cout <<"YES\n";
		else cout <<"NO\n";
	}
}