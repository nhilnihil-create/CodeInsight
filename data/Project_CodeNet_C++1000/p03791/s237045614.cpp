#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#define int long long
#define mod 1000000007
using namespace std;

int a[100000];
signed main() {
	int ans = 1;
	int b; cin >> b;
	for (int c = 0; c < b; c++)cin >> a[c];
	int sum = 1;
	for (int c = 1; c < b; c++) {
		sum++;
		if (sum*2-1>a[c]) {
			ans = ans*sum%mod;
			sum--;
		}
	}
	for(int i=1;i<=sum;i++)ans = ans*i%mod;
	cout << ans << endl;
}