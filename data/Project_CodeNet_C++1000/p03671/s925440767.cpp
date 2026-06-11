#include <bits/stdc++.h>
using namespace std;

int main()
{
  	vector<int> prices(3);
  	for (int i = 0; i < 3; i++) cin >> prices[i];
	sort(prices.begin(), prices.end());
  	int sum = prices[0] + prices[1];
  	cout << sum;
}