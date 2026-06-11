#include <stdio.h>
#include <string.h>

int main()
{
	char String[100001],OutString[100001];
	scanf("%s",String);
	int StringLen = strlen(String),Pos = 0,Diff = 0;
	for(int i = StringLen - 1;i >= 0;i--)
		OutString[Pos] = String[i],Pos++;
	for(int i = 0;i < StringLen;i++)
	{
		if(OutString[i] == 'b') OutString[i] = 'd';
		else if(OutString[i] == 'd') OutString[i] = 'b';
		else if(OutString[i] == 'p') OutString[i] = 'q';
		else if(OutString[i] == 'q') OutString[i] = 'p';
	}
	for(int i = 0;i < StringLen;i++)
		if(OutString[i] != String[i]) Diff++;
	if(Diff == 0) printf("Yes");
	else printf("No");
	return 0;
}