
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;
int N;
bool a[10000000];
int main(void) {
	cin >> N;
	int j = 0;
	while (N!=0) {
		a[j]=true;
		N -= (j + 1);
		if (N < 0) {
			a[-N-1] = false;
			N = 0;
			break;
		}
		j++;
	}
	for (int i = 0; i < 10000000; i++) {
		if (a[i]==true)cout << i + 1 << endl;
	}
	return 0;
}