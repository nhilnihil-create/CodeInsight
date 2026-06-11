#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>
#include <bitset>
#include <vector>
#include <thread>
#include <stack>
#include <map>


using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;
	vector<string> vs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	sort(vs.begin(), vs.end());
	for (auto s : vs)
		cout << s;
}