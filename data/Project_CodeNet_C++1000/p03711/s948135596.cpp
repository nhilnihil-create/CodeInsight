#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//cout<<"GfG!";
	int x, y;
	vector <int> a = {1,3,5,7,8,10,12}, b = {4,6,9,11}, c = {2};
	cin>>x>>y;
	if (count(a.begin(), a.end(), x) && count(a.begin(), a.end(), y))
	    cout<<"Yes";
	else if (count(b.begin(), b.end(), x) && count(b.begin(), b.end(), y))
	    cout<<"Yes";
	else if (count(c.begin(), c.end(), x) && count(c.begin(), c.end(), y))
	    cout<<"Yes";
	else
	    cout<<"No";
	return 0;
}