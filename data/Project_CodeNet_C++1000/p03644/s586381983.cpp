#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
int lst[110] = {1,2,4,8,16,32,64,128};
int main() {
	int n;
	int ans;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		if (n >= lst[i])ans = lst[i];
		else break;
	}
	cout << ans << endl;
	return 0;
}