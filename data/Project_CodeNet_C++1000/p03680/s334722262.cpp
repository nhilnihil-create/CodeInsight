#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> btn(n);
	for (int i = 0; i < n; i++) cin >> btn.at(i);
	for (int i = 0; i < n; i++) btn.at(i)--;
	vector<int> visit(n, -1);
	int count = 0;
	int now = 0;
	int next = 0;
	for (int i = 0; i < n; i++)
	{
		count++;
		next = btn.at(now);
		if (next == 1)
		{
			cout << count << endl;
			return 0;
		}
		if (visit.at(next) != -1) break;
		visit.at(next) = count;
		now = next;
	}
cout << -1 << endl;
return 0;

}
