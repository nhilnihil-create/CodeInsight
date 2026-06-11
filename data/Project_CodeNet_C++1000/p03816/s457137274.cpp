#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include <cstdio>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define swap(a, b, type) { type _tmp = a; a = b; b = _tmp; }
typedef long long ll;
typedef unsigned long long ull;

int cnt[100001] = { 0 };

int main()
{
	int N, A;
	int cards;
	set<int>::iterator front, back, it;
	set<int> nums;

	cin >> N;

	cards = N;

	rep(i, N) {
		cin >> A;

		nums.insert(A);

		cnt[A]++;
		if (cnt[A] >= 3) {
			cnt[A] -= 2;
			cards -= 2;
		}
	}

	front = nums.begin();
	back = nums.end();
	back--;

	while (true) {
		while (cnt[*front] < 2 && front != back) front++;
		while (cnt[*back] < 2 && back != front) back--;

		if (front == back) {
			if (cnt[*front] >= 2) {
				cnt[*front] -= 2;
				cards -= 2;
				continue;
			}
			else break;
		}

		cnt[*front]--;
		cnt[*back]--;
		cards -= 2;
	}

	cout << cards << endl;

	return 0;
}