#include <iostream>
#include <cmath>
using namespace std;
int square(long long int & n)
{
	long long tmp = sqrt(n), ans = 0;
	for(int i = tmp; i >= 1; i--)
    	if( n % i == 0 )
    	{
    		tmp = n/i;
    		while( tmp > 0 )
        	{
        		ans++;
        		tmp /= 10;
        	}
        	return ans;
      	}
}
int main()
{
	long long int n;
  	cin >> n;
  	cout << square(n);
}