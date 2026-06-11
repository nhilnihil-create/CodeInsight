#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> a(26);
	for(char c: s) a[c-'a']++;
	
	for(int i: a) {
		if(i % 2) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}
