#include <iostream>
#include <cstdio>
using namespace std;

long long x, y;
int main()
{
	cin >> x >> y;
    cout << ((x - y) > 1 || (x - y) < -1 ? "Alice" : "Brown") << endl;
    return 0;
}