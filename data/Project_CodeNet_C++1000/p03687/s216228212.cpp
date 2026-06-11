#include <iostream>
#include <sstream>
#include <stdio.h>
//#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))

using namespace std;


int main(void)
{
	string s; cin >> s;
	map<char, int> cnt; rep(i, 0, s.size())cnt[s[i]]++;
	int m = 100;
	for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
		int tmp = 0, tmp_m = 0;
		rep(i, 0, s.size()) {
			if (s[i] == it->first) {
				tmp_m = max(tmp_m, tmp);
				tmp = 0;
			}
			else tmp++;
			if (i == s.size() - 1)tmp_m = max(tmp_m, tmp);
		}
		m = min(m, tmp_m);
	}
	cout << m << endl;

	return 0;
}