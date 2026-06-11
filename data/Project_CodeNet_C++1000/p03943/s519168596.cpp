#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void) {
	vector<int> arr(3);
	for (int i = 0; i < 3; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	if (arr[0] + arr[1] == arr[2])
		puts("Yes");
	else
		puts("No");
	return 0;
}