#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n, f[277], mx[N];
string s, re;

vector <int> v[256];

int min_f() {

}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;

	int ans = 1, nr = 0;
	for(int i = s.size() - 1; i >= 0; i--) {
		v[s[i]].push_back(i);
		f[s[i]]++;

		if(f[s[i]] == 1) nr++;
		
		if(nr == 26) {
			ans++;
			nr = 0;
			for(int j = 'a'; j <= 'z'; j++) f[j] = 0;
		}
		mx[i] = ans - 1;
	}
	dbg(ans);
	// dbg(v['a']);
	// dbg(v['c']);

	for(int i = 0; i < ans; i++) {
		int lim = s.size();
		for(int j = 'a'; j <= 'z'; j++) {
			if(v[j].empty() || mx[v[j].back() + 1] < ans - i - 1) {
				re += j;
				if(!v[j].empty())
					lim = v[j].back();
				break;
			}
		}
		// if(lim == 0) dbg(i);
		for(int j = 'a'; j <= 'z'; j++)
			while(!v[j].empty() && v[j].back() <= lim)
				v[j].pop_back();
	}
	cout << re << '\n';
}	
	
	