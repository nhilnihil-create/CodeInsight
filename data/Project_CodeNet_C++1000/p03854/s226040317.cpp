
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void ABC049();

int main()
{
	ABC049();
	fflush(stdout);
	return 0;
}

static void ABC049()
{
	std::string orgs;
	std::cin >> orgs;

	int nowPos = 0;
	int sLen = orgs.length();
	std::string last;
	std::string bfr;
	while(nowPos < sLen) {
		std::string tmp;
		for (int j = nowPos; (j < nowPos + 5) && (j < sLen); j++) {
			tmp += orgs[j];
		}
		if ((tmp == "dream") || (tmp == "erase")) {
			bfr = tmp;
			nowPos += 5;
		}
		else {
			if ((tmp.size() >= 2) && (tmp[0] == 'e') && (tmp[1] == 'r') && (bfr == "dream")) {
				bfr = "dreamer";
				nowPos += 2;
			}
			else if ((tmp.length() >= 1) && (tmp[0] == 'r') && (bfr == "erase")) {
				bfr = "eraser";
				nowPos += 1;
			}
			else {
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}
