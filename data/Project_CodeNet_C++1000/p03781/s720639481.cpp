
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<numeric>
#include<vector>
#include<tuple>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
typedef long long ll;
const int MOD = 1e9 + 7;

int N;
int main(void)
{
	cin >> N;
	ll log;
	FOR(i, 1, 100000) {
		ll c = i * (i + 1) / 2;
		if (c >= N) {
			log = i;
			break;
		}
	}
	cout << log << endl;
	return 0;
}