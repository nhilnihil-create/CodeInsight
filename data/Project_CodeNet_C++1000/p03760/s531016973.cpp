#include <iostream>
#include <string>

using namespace std;

int main()
{
	string O, E;
	cin >> O >> E;

	string ans;
	for (size_t i = 0; i < O.size() || i < E.size(); ++i) {
		if (i < O.size()) {
			ans += O[i];
		}
		if (i < E.size()) {
			ans += E[i];
		}
	}
	cout << ans << endl;
}
