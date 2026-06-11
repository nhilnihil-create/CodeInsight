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
	int n,cnt=0, ans=0;
	char s;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> s;
		if (s == 'I')cnt++;
		else cnt--;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}