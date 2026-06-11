#include <iostream>
using namespace std;	
unsigned long long n,m;
int main()
{
	cin >> n >> m;
   	cout << min(n + m / 2,m) / 2 << endl;
    return 0;
}