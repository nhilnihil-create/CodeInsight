#include <stdio.h>
#include <string>

int main()
{
	int N,M;

	scanf ("%d %d",&N,&M);
	for (int i=1;i<=N;i++) for (int j=0;j<M;j++){
		char S[7];
		scanf ("%s",S);
		std::string st = S;
		if (st == "snuke"){
			printf ("%c%d\n",j+'A',i);
			return 0;
		}
	}

	return 0;
}