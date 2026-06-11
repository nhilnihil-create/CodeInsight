#include <iostream>
using namespace std;
typedef long long int LLI;

LLI gcd(LLI a, LLI b)
{
	LLI tmp;
	while( b != 0 )
	{
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
    LLI n, second = 1, first, tmp = 1;
    cin >> n;
    
    if( n >= 1 ){
    	cin >> first;
    	tmp = first;
	}
	if( n >= 2 ){
		second = first;
		cin >> first;
		tmp = first / gcd(first,second) * second;
	}
    for(int i = 2; i < n; i++){
    	second = tmp;
		cin >> first;
    	tmp = first / gcd(first,second) * second;
	}
	cout << tmp;
}