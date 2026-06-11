#include <iostream>
#include<cstring>
char a[1000000];
using namespace std;
int main()
{
	cin >> a + 1;
	int flag = 0;
	int len = strlen(a + 1);
	for (int i = 1; i < len; i++)
	{
		if (i + 1 <= len && a[i + 1] == a[i])
		{
			cout << i << " " << i + 1 << endl;
			flag = 1;
			break;
		}
		if (i + 2 <= len && a[i + 2] == a[i])
		{
			cout << i << " " << i + 2 << endl;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	cout << "-1 -1" << endl;
}