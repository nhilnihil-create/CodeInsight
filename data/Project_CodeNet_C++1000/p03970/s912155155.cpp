#include<cstdio>
#include<cstring> 
using namespace std;
char s[55], S[55] = {'C', 'O', 'D', 'E', 'F', 'E', 'S', 'T', 'I', 'V', 'A', 'L', '2', '0', '1', '6'};
int main()
{
	scanf("%s", s);
	int ans = 0;
	for(int i = 0; i < strlen(s); i++)
		if(s[i] != S[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
