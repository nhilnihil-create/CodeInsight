#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<time.h>
#include<set>
#include<map>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;

ll N;
ll a[200000];

int main() {
	

	cin >> N;
	ll sum = 0;
	FOR(i,0,N) {
		cin >> a[i];
		sum += a[i];
	}

	int flag = 1;
	ll sum1=0;
	ll cur = 1e18;
	FOR(i, 0, N-1) {
		sum1 += a[i];
		if (cur > abs(sum - 2 * sum1))cur= abs(sum - 2 * sum1);
	}
	cout << cur << endl;

	return 0;
}