#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	getline(cin, s);
	getline(cin, s);
	string::iterator it;
	int x = 0, peak = 0;
	for(it = s.begin(); it<s.end(); it++){
		if(*it=='I')x++;
		else x--;

		peak = max(peak,x);
	}
	
	cout << peak << endl;
}