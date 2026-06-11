#include <bits/stdc++.h>

using namespace std;

int read()
{
	int sum = 0, flag = 1;
	char c = getchar();
	for (;c  < '0' ||c >  '9' ;  c= getchar() )
	 if ( ! (c ^ '-') ) flag = - 1;
	for (;c  >= '0' && c <= '9' ; c = getchar() )
	 sum = (sum << 3) + (sum << 1) + (c ^ 48);
	return sum * flag;
} 

int n = read();

int a[1000005];

inline bool cmp(int a, int b)
{
	return a > b;
}

inline void init()
{
	for (int i = 1; i <= n ; i ++)
	 a[i] = read();
	sort(a + 1, a + n + 1, cmp);
}

inline void work()
{
	int cheak = 1;
	for (int i = 1; i <= n ; i++)
	 if (i >= a[i + 1])
	  {
	    for (int j = i + 1 ; ! ( a[j] ^ i ) ; j ++)
		 cheak ^= 1;
		cheak &= (a[i] - i + 1);
		printf(  cheak ? "Second\n" : "First\n"  );
		break;
	  } 
	return;
}

int main()
{
	init();
	work();
	return 0;
}