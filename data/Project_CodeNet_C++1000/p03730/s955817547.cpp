#include <iostream>
using namespace std;
typedef long long int LLI;
string check( int a, int b, int c )
{
	if( a % b == c )
		return "YES";
	
	int start = a % b, tmp = (2 * start) % b;
	
	while( start != tmp ){
    	if( tmp == c )
    		return "YES";
    	tmp += a;
    	tmp %= b;
    }
	return "NO";
}
int main()
{
  	int a, b, c;
  	cin >> a >> b >> c;
  	cout << check(a,b,c);
	return 0;
}