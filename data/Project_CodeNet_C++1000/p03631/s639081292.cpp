#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;
int main() {
	string s; cin >> s;
	string s_c = s;
	reverse(s.begin(), s.end());
	if (s == s_c)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
