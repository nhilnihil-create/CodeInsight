#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>

using std::cin;
using std::cout;

const int MaxN = 100005;

int n, arr[MaxN];

int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	std::copy_n(std::istream_iterator<int>(cin), n, arr);
	std::sort(arr, arr + n, std::greater<int>());
	arr[n] = 0;
	int p = 0;
	while (arr[p + 1] > p + 1) ++p;
	int q = p;
	while (arr[q + 1] == p + 1) ++q;
	int a = arr[p] - p;
	int b = q - p + 1;
	cout << ((a & b & 1) ? "Second" : "First") << '\n';
	return 0;
}