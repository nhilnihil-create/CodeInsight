#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
	char s1[17] = "CODEFESTIVAL2016",s2[17];
	int num = 0 ,i;
	scanf("%s",s2);
	for (i = 0 ;i < 16 ;i++) {
		if (s1[i] != s2[i]) {
			num++;
		}
	}
	printf("%d\n",num);
	return 0;
 } 