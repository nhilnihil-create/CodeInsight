/*
 * ARC082_D.cpp
 *
 *  Created on: Jun 5, 2018
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

int p[100001];
//vector<int> con;
//
//int main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//
//	int N;
//	cin >> N;
//	FOR(i, 1, N) {
//		cin >> p[i];
//	}
//
//	bool start = true;
//	FOR(i, 1, N) {
//		if(start && p[i]==i) {
//			con.pb(0);
//			start = false;
//		}
//		if(p[i] == i) con[con.size()-1]++;
//		else start = true;
//	}
//
//	int ans = 0;
//	REP(i, SZ(con)) {
//		ans += con[i]/2;
//		if(con[i]%2 == 1) {
//			ans++;
//		}
//	}
//
//	cout << ans << endl;
//}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> p[i];
	}
	int ans = 0;
	FOR(i, 1, N) {
		if(p[i]==i && i<N) {
			swap(p[i], p[i+1]);
			ans++;
		}
		else if(p[i]==i && i==N) {
			ans++;
		}
	}
	cout << ans << endl;
}




