#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
#define mp(a, b) make_pair(a, b)
/*
map<pair<int, int>, int> M;
int sg(int x, int y)
{
	if(x > y) swap(x, y);
	if(x <= 1 && y <= 1) return 0;
	if(M.count(mp(x, y))) return M[mp(x, y)];
	unordered_set<int> s;
	for(int i = 2; i <= x; i += 2) s.insert(sg(x - i, y + i / 2));
	for(int i = 2; i <= y; i += 2) s.insert(sg(x + i / 2, y - i));
	for(int i = 0; ; ++i)
		if(!s.count(i))
			return M[mp(x, y)] = i;
}
*/
int main()
{
	ll x, y;
	cin >> x >> y;
	if(abs(x - y) <= 1) puts("Brown");
	else puts("Alice");
	return 0;
}