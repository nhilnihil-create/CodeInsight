#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;

char str[200005];
int main()
{
	for (int i = 0; i < 200005; i++)
	{
		str[i] = '+';
	}
	cin >> str;
	/*int left, right;
	left = 0;
	right = 1;
	while (str[right] != '+')
	{
		if (str[left] == 'S' && str[right] == 'T')
		{
			str[left] = '+';
			str[right] = '+';
			bool findout=
			if (left == 0)
			{
				left = right + 1;
				right = right + 2;
			}
			else
			{

			}
		}
		else if()

	}
	*/
	int i = 0;
	for (; i < 200005; i++)
	{
		if (str[i] == '\0')
			break;
	}
	int counts, countt;
	counts = 0, countt = 0;
	for (int j = i-1; j >=0; j--)
	{
		if (str[j] == 'T')
		{
			countt++;
		}
		if (str[j] == 'S' && countt > 0)
		{	
			counts++;
			countt--;
	    }
		
	}
	cout << i-(counts*2);
	

	
}