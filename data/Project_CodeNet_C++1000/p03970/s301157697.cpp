#include <iostream>
#include <cstring>
using namespace std;

char s[] = "CODEFESTIVAL2016";
char ss[100];
int main(void)
{
	int k = strlen(s);
	cin >> ss;
	int ans = 0;
	for(int i=0; i<k; ++i)
	{
		if(ss[i] != s[i])
			ans++;
	}
	cout << ans << endl;
	
	return 0;
}