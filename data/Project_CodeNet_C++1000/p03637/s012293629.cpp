#include<cstdio>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<climits>
#include<functional>

#include<memory.h>

#define ll long long

using namespace std;


int main()
{
	int N(0);
	while (cin >> N) {
		int num(0);
		int count0(0), count1(0), count2(0);
		for (int i = 0; i < N; ++i) {
			cin >> num;
			if (num % 4 == 0) {
				++count2;
			}
			else if (num % 2 == 0) {
				++count1;
			}
			else {
				++count0;
			}
		}

		if (count2 >= count0 || (count2 == count0 - 1 && count1 == 0)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}