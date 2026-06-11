#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;
int main()
{
	int n, i;
	cin >> n;
	LLI arr[n], biggest = 0, second = 0;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
		
	sort(arr,arr+n);
	
	for( i = n-1; i >= 1; i--)
		if( arr[i] == arr[i-1]  )
		{
			biggest = arr[i];
			break;
		}
	for(int j = i-2; j >= 1; j-- )
		if( arr[j] == arr[j-1] )
		{
			second = arr[j];
			break;
		}
	cout << biggest * second;
}