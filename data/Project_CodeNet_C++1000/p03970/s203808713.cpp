#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	string str = "CODEFESTIVAL2016";
	cin >> a;
	int k = 0;
	for(int i = 0;i < 16;i++)
	    {
	    	if(a[i] != str[i])k++;
		}
	cout << k << endl;
	return 0;
}