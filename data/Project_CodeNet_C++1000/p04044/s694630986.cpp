#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	vector<string> v;
	int x,y;

	cin>>x>>y;

	for(int i=0;i<x;i++) {
		cin>>s;
		v.push_back(s);
	}

	sort(v.begin(),v.end());

	for(int i=0;i<x;i++) {
		cout<<v[i];
	}

	return 0;
}