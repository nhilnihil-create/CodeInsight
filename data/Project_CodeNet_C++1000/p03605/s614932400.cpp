#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string N;
	cin >> N;
	printf(N[0] == '9' || N[1] == '9' ? "Yes\n" : "No\n");
	return 0;
}
