#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
int n;
ll a[N];
struct node { ll a, b, v; };
stack< node > s;
ll ans = 0;

inline ll read() {
	ll s = 0, f = 1;
	char ch;
	for(; ch < '0' || ch > '9'; ch = getchar())	if(ch == '-')	f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar())	s = (s << 1) + (s << 3) + ch - '0';
	return s * f;
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++i)	a[i] = read();
	node f, g;
	f.a = f.b = 1;
	f.v = a[1];
	s.push(f);
	for(int i = 2; i <= n; ++i) {
		g.a = g.b = 1;
		g.v = a[i];		
		while(!s.empty() && g.v <= s.top().v) {
			f = s.top();
			s.pop();
			if(!s.empty())	s.top().a += f.a;
			g.b += f.b;
			ans += f.a * f.b * f.v;
		}
		s.push(g);
	}
	while(!s.empty()) {
		f = s.top();
		s.pop();
		if(!s.empty())	s.top().a += f.a;
		ans += f.a * f.b * f.v;
	}
	
	printf("%lld\n", ans);
	return 0;
}