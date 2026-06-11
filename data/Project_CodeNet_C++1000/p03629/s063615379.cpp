#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<unordered_set>
#include<set>
#include<stack>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	string A;
	cin >> A;
	int n = A.size();
	unordered_set<char> us;
	stack<int,vector<int>> index;
	index.push(n);
	for (int i = n - 1; i >= 0; --i) {
		us.insert(A[i]);
		if (us.size() == 26) {
			index.push(i);
			us.clear();
		}
	}
	
	string ans;
	int i = 0;
	set<char> s;
	while (index.size()) {
		s.clear();
		for (char c = 'a'; c <= 'z'; ++c) {
			s.insert(c);
		}
		int j = index.top(); index.pop();
		for (int k = i; k < j; ++k) {
			s.erase(A[k]);
		}
		char c = *(s.begin());
		ans += c;
		i = A.find(c, j)+1;
	}
	cout << ans << endl;
	return 0;
}