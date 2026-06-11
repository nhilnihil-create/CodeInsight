#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> l(2 * n,0);
	for(int i=0;i<2*n;i++)
	{
		cin >> l.at(i);
	}
	sort(l.begin(),l.end());
	int sm = 0;
	for(int i=0;i<2*n;i++)
	{
		if(i % 2 == 0)
		{
			sm += l.at(i);
		}
	}
    cout << sm << endl;
	return 0;
}
