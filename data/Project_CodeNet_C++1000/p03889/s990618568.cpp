#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
char a[100005], b[100005];
int main()
{
	cin >> a;
	int len = strlen(a),jian=0;
	for (int i = 0; i < len; i++)
	{
		b[i] = a[len - i-1];
		if (b[i] == 'd')b[i] = 'b';
		else if (b[i] == 'b')b[i] = 'd';
		else if (b[i] == 'p')b[i] = 'q';
		else if (b[i] == 'q')b[i] = 'p';
		if (b[i] != a[i]) { jian = 1; break; }
	}
	if (jian == 0)cout << "Yes";
	else cout << "No";
	return 0;
}

