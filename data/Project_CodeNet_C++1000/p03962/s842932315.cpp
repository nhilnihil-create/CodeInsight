#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	set<int> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	cout << s.size() << endl;
	return 0;
}