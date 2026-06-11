#include<cstdio>
#include<cstring>
using namespace std;

char a[100005];
char b[100005];
int len1,len2;

int main()
{
	scanf("%s",a);
	len1 = strlen(a);
	for (int i = 0;i < len1;i++)
		b[i] = a[i];
	len2 = len1 / 2;
	for (int i = 0;i < len2;i++)
	{
		char k;
		k = a[i];
		a[i] = a[len1 - 1 - i];
		a[len1 - 1 - i] = k;
	}
	for (int i = 0;i < len1;i++)
	{
		if (a[i] == 'b') a[i] = 'd';
		else if (a[i] == 'd') a[i] = 'b';
		else if (a[i] == 'p') a[i] = 'q';
		else if (a[i] == 'q') a[i] = 'p';
	}
	for (int i = 0;i < len1;i++)
		if (a[i] != b[i])
		{
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}