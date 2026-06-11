#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int LLI;
int main()
{
	int n, max = 0, tmp, s1, s2, s3;
	cin >> n;
	unordered_map <int, int> arr;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr[tmp]++;
		s1 = arr[tmp-1] + arr[tmp] + arr[tmp+1];
		s2 = arr[tmp+2] + arr[tmp] + arr[tmp+1];
		s3 = arr[tmp-1] + arr[tmp] + arr[tmp-2];
		if( max < s1 )
			max = s1;
		if( max < s2 )
			max = s2;
		if( max < s3 )
			max = s3;
	}
	cout << max;
}