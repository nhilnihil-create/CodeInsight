#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
 
int main() {
	int h, w;
	string s[105];
	int i, j;
	cin >> h >> w;

	for (i = 0; i < h; i++)
	{
		cin >> s[i];
	}
	for (i = -1; i <= w; i++)
	{
		cout << '#';
	}
	cout << endl;
	for (i = 0; i < h; i++)
	{
		cout << '#' << s[i] << '#'<<endl;
	}
	for (i = -1; i <= w; i++)
	{
		cout << '#';
	}
	cout << endl;
}
