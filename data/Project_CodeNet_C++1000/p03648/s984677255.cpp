/*
 * ARC079_D.cpp
 *
 *  Created on: Jun 6, 2018
 *      Author: 13743
 */
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;

#define pb push_back
#define SZ(a) int((a).size())
#define ALL(a) (a).begin(), (a).end()
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) FOR(i,0,n-1)
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

lng power(lng b, lng e) {lng sol=1; while(e>0) {if(e&1) {sol=sol*b;} e>>=1; b*= b;} return sol;}

lng lim = 1000 + 10000000000000000LL;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	lng K;
	cin >> K;

	if(K == 0) {
		cout << 2 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	if(K == 1) {
		cout << 2 << endl;
		cout << 0 << " " << 2 << endl;
		return 0;
	}

	lng n, c, p;
	FOR(i, 2, 50) {
		lng d = K / i;
		lng r = K % i;
		if(d < 1) continue;
		if(i+d-1+r > lim) continue;
		n = i;
		c = d-1;
		p = r;
		break;
	}

	cout << n << endl;
	REP(i, n) {
		if(i > 0) cout << " ";
		lng x = i+1 + c;
		if(i >= n-p) x += 1;
		cout << x;
	}
	cout << endl;
}




