#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll calc(string s, int flag)
{
	vector<string> sub;
	int off = 0;
	for (int p = 1; p < s.size(); ++p) {
		if (flag & 1) {
			sub.push_back(s.substr(off, p - off));
			off = p;
		}
		flag = flag >> 1;
	}
	sub.push_back(s.substr(off, s.size() - off));

	ll sum = 0;
	for (int i = 0; i < sub.size(); ++i) {
		sum += stoi(sub[i]);
	}
	return sum;
}

int main()
{
	string S; cin >> S;
	int flag = 0;
	for (int i = 0; i < S.size() - 1; ++i) {
		flag = (flag << 1) + 1;
	}
	ll sum = stold(S);
	while (flag) {
		sum += calc(S, flag);
		--flag;
	}
	cout << sum << endl;
}
