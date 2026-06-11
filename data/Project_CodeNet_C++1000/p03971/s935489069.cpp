#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	int n, a, b, cnt=0 , b_cnt=0;
	string s;
	cin >> n >> a >> b >> s;
	for (int i = 0;i < n;i++) {
		if (s[i] == 'a' && cnt < a + b) {
			cnt += 1;
			cout << "Yes" << endl;
		}
		else if (s[i] == 'b' && cnt < a + b && b_cnt < b) {
			cnt += 1;
			b_cnt += 1;
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
}