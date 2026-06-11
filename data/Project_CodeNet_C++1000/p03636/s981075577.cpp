#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ordor,result;

	cin >> ordor;

	result = to_string(ordor.size() - 2);

	cout << ordor[0]<< result << ordor[ordor.size() - 1];

	return 0;
}