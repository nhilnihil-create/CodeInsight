#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main()
{
	int w, a, b;
	cin >> w >> a >> b;
	int c= max(a, b) - min(a + w, b + w);
	if (c > 0)
		cout << c;
	else
		cout << 0;
    return 0;
}