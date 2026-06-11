#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int LLI;
int main()
{
	int n, ans = 0, tmp;
	cin >> n;
	unordered_map <int, int> arr;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr[tmp]++;
		if( arr[tmp] % 2 == 1 )
			ans++;
		else
			ans--;
	}
	cout << ans;
}