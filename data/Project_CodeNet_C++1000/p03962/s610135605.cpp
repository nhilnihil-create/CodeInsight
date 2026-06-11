#include<bits/stdc++.h>
using namespace std;

int main()
{
	unordered_set<int> k;
	for(int i=0; i<3; i++) {
		int x;
		cin >> x;
		k.insert(x);
	}
	cout << k.size();
}
