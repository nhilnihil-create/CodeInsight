#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

struct info{
	LLI rep;
	LLI value;
};

bool by_value(info & a, info & b)
{
	return a.value < b.value;
}

int main()
{
	LLI n, k, a, b;
	cin >> n >> k;
	
	info arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr[i].rep = b;
		arr[i].value = a;
	}
	sort(arr,arr+n,by_value);
	
	for(int i = 0; i < n; i++)
	{
		if( k <= arr[i].rep )
		{
			cout << arr[i].value;
			break;
		}
		k -= arr[i].rep;
	}
	
	return 0;
}