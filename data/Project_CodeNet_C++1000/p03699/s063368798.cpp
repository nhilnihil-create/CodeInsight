#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;
int main()
{
	int n;
	cin >> n;
	int arr[n], sum = 0, count = 0;
	for(int i = 0; i < n; i++)
    {
    	cin >> arr[i];
    	if( arr[i] % 10 == 0)
    		count++;
    	sum += arr[i];
    }
    if( count == n )
    	cout << 0;
	else if( sum % 10 == 0 )
    {
    	sort(arr,arr+n);
    	for(int i = 0; i < n; i++)
        	if( arr[i] % 10 != 0 )
            {
            	cout << sum - arr[i];
            	break;
            }
    }else
    	cout << sum;
  	
	return 0;
}