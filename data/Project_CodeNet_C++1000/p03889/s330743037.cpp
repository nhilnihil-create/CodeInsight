#include <cstdio>
#include <cstring>
using namespace std;

const int N=100013;
char cc[N];

signed main(void)
{
	scanf("%s", cc);
	int len=strlen(cc);
	for(int i=0, j=len-1; i<=j; ++i, --j)
	{
		if(cc[i] == 'b')
			if(cc[j] != 'd')
				goto Ne;
		if(cc[i] == 'd')
			if(cc[j] != 'b')
				goto Ne;	
		if(cc[i] == 'p')
			if(cc[j] != 'q')
				goto Ne;
		if(cc[i] == 'q')
			if(cc[j] != 'p')
				goto Ne;					
	}
	puts("Yes");
	return 0;
	
	Ne:
		puts("No");
		return 0;
}
