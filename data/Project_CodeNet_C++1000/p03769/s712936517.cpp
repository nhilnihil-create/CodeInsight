#include <iostream>
#include <vector>

using namespace std;

long long n, id, tot;

vector<long long> st, ed;

int main()
{
	cin >> n;
	while (n)
	{
		if (n & 1) ed.push_back(tot++), n >>= 1;
		else st.push_back(tot++), n--;
	}
	
	tot = st.size() + ed.size();
	
	cout << tot + 100 << endl;
	for (int i = 0; i < st.size(); i++) cout << tot-st[i] << " ";
	for (int i = ed.size()-1; i >= 0; i--) cout << tot-ed[i] << " ";
	for (int i = 1; i <= 100; i++) cout << i << " ";
	
	return 0;
}