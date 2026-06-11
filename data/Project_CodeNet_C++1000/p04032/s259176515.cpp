#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

char s[N];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	
	for (int i = 1; i <= n - 1; i ++ )
		if (s[i] == s[i + 1])
		{
			printf("%d %d\n", i, i + 1);
			return 0;
		}
	
	for (int i = 1; i <= n - 2; i ++ )
		if (s[i] == s[i + 2])
		{
			printf("%d %d\n", i, i + 2);
			return 0;
		}
	
	puts("-1 -1");
    return 0;
}