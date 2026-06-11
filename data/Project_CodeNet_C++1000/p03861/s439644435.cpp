#include <iostream>
using namespace std;

int main()
{
	long long a, b, c;
  	cin >> a >> b >> c;
  	if(a==0)cout << b/c+1;
  	else cout << b/c-(a-1)/c;
}
