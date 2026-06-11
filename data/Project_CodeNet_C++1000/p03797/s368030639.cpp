#include <iostream>
using namespace std;
int main()
{
	long long s,c,k;
    cin >> s >> c;
    k = min(s,c / 2);
    c = c - s * 2;
	s = 0;
    c = max(c,s);
    cout << k + c / 4 << endl;
    return 0;
} 