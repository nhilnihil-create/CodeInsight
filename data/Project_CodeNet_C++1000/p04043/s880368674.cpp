#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	
	sort(v.begin(),v.end());
	if(v[0] == 5 && v[1] == 5 && v[2] == 7) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}