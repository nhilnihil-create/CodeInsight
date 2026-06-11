#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int main()
{
	i64 N;
	scanf("%lld", &N);
	N += 1; // empty string

	vector<int> seq;
	int last = 1;

	bool flg = false;
	for (int i = 40; i >= 0; --i) {
		if ((N >> i) & 1) {
			if (flg) {
				seq.push_back(last++);
				seq.insert(seq.begin(), last++);
			} else {
				flg = true;
				//seq.push_back(last++);
			}
			//flg = true;
		} else if (flg) {
			seq.push_back(last++);
		}
	}
	for (int i = 1; i < last; ++i) seq.push_back(i);
	printf("%d\n", seq.size());
	for (int i = 0; i < seq.size(); ++i) printf("%d%c", seq[i], i == seq.size() - 1 ? '\n' : ' ');
	return 0;
}
