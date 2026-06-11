#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, l;
	cin>>n>>l;
	vector<string> v(n);
	for(int i = 0; i < n; i++) {
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	string ans = "";
	for(string s: v) {
		ans += s;
	}
	cout<<ans;
}
