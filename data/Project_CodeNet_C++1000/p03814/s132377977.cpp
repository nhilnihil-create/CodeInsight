#include <iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string s; 
	int z;
	cin >> s; int c = 0; 
	c = s.find_first_of('A');
	z = s.find_last_of('Z');
	cout << z - c + 1;
}

