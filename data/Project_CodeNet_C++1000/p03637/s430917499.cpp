#include<iostream>
using namespace std;
int main()
{
	int n,t1=0,t2=0,t3=0;
	cin >> n;
 	while (n--)
	{
		int t;
		cin >> t;

		if (t % 4 == 0)t1++;
		else if (t % 2 == 0)t2++;
		else t3++;
	}
	if (t2 > 0 && t3<= t1)
		printf("Yes\n");
	else if (t2 == 0 && t3 <= t1 + 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}