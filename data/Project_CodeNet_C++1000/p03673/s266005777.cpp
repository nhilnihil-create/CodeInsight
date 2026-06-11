#include <iostream>
using namespace std;
typedef long long int LLI;

int main()
{
	int n;
	cin >> n;
	int arr[n], ans[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n/2; i++)
	{
		ans[i] = arr[n-1-2*i];
		ans[n-1-i] = arr[n-2-2*i];
	}
	if( n % 2 == 1 )
		ans[n/2] = arr[0];
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
}