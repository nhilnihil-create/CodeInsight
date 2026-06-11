#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	LLI n, t, a;
	cin >> n >> t >> a;
	
	LLI min_t = t, min_a = a, div_a, div_t, max;
	for(LLI i = 0; i < n-1; i++)
	{
		cin >> t >> a;
		if( min_a % a == 0 )
			div_a = min_a / a;
		else
			div_a = min_a / a + 1;
			
		if( min_t % t == 0 )
			div_t = min_t / t;
		else
			div_t = min_t / t + 1;
		
		max = div_t > div_a ? div_t : div_a;
		
		min_a = a * max;
		min_t = t * max;
	}
	cout << min_t + min_a;
}