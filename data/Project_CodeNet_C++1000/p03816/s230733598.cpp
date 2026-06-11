#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int a[N];


int main ()
{
	int n;
	cin >> n;
	set<int>st;
	for (int i = 0; i < n ; i ++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	cout << st.size()-(st.size()%2?0:1) << endl;
	
	return 0;
}
