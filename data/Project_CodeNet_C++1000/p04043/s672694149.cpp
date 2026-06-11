#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>
#include <bitset>
#include <vector>
#include <thread>
#include <stack>
#include <map>


using namespace std;

int main()
{
	int a = 0, b = 0, c;
	for (int i = 0; i < 3; i++)
	{
		cin >> c;
		if (c == 5) a++;
		else if (c == 7) b++;
	}
	if (a == 2 && b == 1) printf("YES");
	else printf("NO");
}