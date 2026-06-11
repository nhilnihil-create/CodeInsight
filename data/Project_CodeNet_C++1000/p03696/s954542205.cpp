
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC064D();

#if 1
int main()
{
	ABC064D();
	fflush(stdout);
	return 0;
}
#endif

class RunLengthEnc {
public:
	class RLEData {
	public:
		char c = 0;
		int cnt = 0;
	};

	typedef std::vector<RLEData> RLEvec;

	void Exec(RLEvec& vRle, const char* str) {
		int sLen = strlen(str);

		char bfr = 0;
		RLEData ccnt;
		for (int i = 0; i < sLen; i++) {
			if (str[i] != bfr) {
				if (ccnt.c != 0) {
					vRle.push_back(ccnt);
				}
				ccnt.c = str[i];
				ccnt.cnt = 1;
			}
			else {
				ccnt.cnt++;
			}
			bfr = str[i];
		}
		if (ccnt.c != 0) {
			vRle.push_back(ccnt);
		}
	}
};

static void ABC064D()
{
	int N;
	getint(N);
	std::string orgs;
	std::cin >> orgs;
	
	RunLengthEnc rle;
	RunLengthEnc::RLEvec data;

	rle.Exec(data, orgs.c_str());

	int leftCount = 0,  addLeft = 0, addRight = 0;
	for (auto it = data.begin(); it != data.end(); it++) {
		if (it->c == '(') {
			leftCount += it->cnt;
		}
		else {
			leftCount -= it->cnt;
			if (leftCount < 0) {
				addLeft += std::abs(leftCount);
				leftCount = 0;
			}
		}
	}
	addRight = leftCount;

	for (int i = 0; i < addLeft; i++) {
		orgs.insert(orgs.begin(), '(');
	}
	for (int i = 0; i < addRight; i++) {
		orgs += ')';
	}
	printf("%s\n", orgs.c_str());
}
