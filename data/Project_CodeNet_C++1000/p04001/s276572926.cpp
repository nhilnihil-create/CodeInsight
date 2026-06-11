#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;



int main() {
	string s;
	cin >> s;
	long long len = (long long)s.length();
	long long sum = 0;
	for (long long bit = 0; bit < (1 << len - 1); ++bit) {
		vector<long long> v;
		string str = s;
		long long ilast = 0;
		for (long long i = 0; i < len - 1; i++) {
			if (bit & (1 << i)) {
				istringstream ss;
				ss = istringstream(s.substr(ilast, i + 1 - ilast));
				long long num;
				ss >> num;
				sum += num;
				ilast = i + 1;
			}
		}
		istringstream sstail;
		sstail = istringstream(s.substr(ilast, len));
		long long numtail;
		sstail >> numtail;
		sum += numtail;
	}

	cout << sum << endl;
	return 0;
}