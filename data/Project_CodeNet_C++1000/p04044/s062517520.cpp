#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	int n, l, i;
	cin >> n >> l;
	vector<string> s;
	for(i=0; i<n; i++){
		string s1;
		cin >> s1;
		s.push_back(s1);
	}
	sort(s.begin(), s.end());
	for(i=0; i<n; i++){
		cout << s[i];
	}
	cout << endl;
	return 0;
}
