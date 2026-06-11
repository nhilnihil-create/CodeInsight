#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
#define mp make_pair
#define P pair<int,int>
#define enld endl


int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	int cntR = 0;
	rep(i, N) {
		if (S[i] == '(') {
			cntR++;
		}
		else if (S[i] == ')') {
			if (cntR > 0) {
				cntR--;
			}
		}
	}
	reverse(S);
	string SS = S;
	rep(i, N) {
		if (SS[i] == ')') {
			SS[i] = '(';
		}
		else {
			SS[i] = ')';
		}
	}
	//cout << S << endl;
	int cntL = 0;
	rep(i, N) {
		if (SS[i] == '(') {
			cntL++;
		}
		else if (SS[i] == ')') {
			if (cntL > 0) {
				cntL--;
			}
		}
	}
	reverse(S);
	rep(i, cntL) {
		cout << '(';
	}
	cout << S;
	rep(i, cntR) {
		cout << ')';
	}
	cout << endl;
	//cout << cntL << ' ' << cntR << endl;
}