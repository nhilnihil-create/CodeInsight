#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
int q, a, b, c, d, ss[MX], tt[MX];
string s, t;
int main(){
	cin >> s >> t >> q;
	rep(i,s.size()) ss[i+1] = ss[i] + 1 + (s[i] == 'A');
	rep(i,t.size()) tt[i+1] = tt[i] + 1 + (t[i] == 'A');
	rep(i,q){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		puts((ss[b] - ss[a-1] - tt[d] + tt[c-1]) % 3 == 0 ? "YES" : "NO");
	}
}