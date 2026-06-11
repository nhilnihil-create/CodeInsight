#include <iostream>
using namespace std;

int n[100];

int main()
{
	string n;
	cin >> n;
	int k = n.size();
	for (int i = 0; i < k; ++i)
	{
		cin >> n[i];
		if (n[i] == '9')
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
