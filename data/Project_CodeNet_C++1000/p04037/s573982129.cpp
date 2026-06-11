#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read()
{
    int x = 0,f = 1;char ch = getchar();
    for(;!isdigit(ch);ch = getchar())if(ch == '-')f = -f;
    for(;isdigit(ch);ch = getchar())x = 10 * x + ch - '0';
    return x * f;
}
const int maxn = 1e5 + 10;
int n;int a[maxn];
int main()
{
    n = read();
    for(int i=1;i<=n;i++)a[i] = read();
    sort(a + 1,a + n + 1);reverse(a + 1,a + n + 1);
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(i + 1 > a[i + 1])
		{
			for(int j=i+1;a[j] == i;j++) ans ^= 1;
        	ans |= (a[i] - i) & 1;
        	if(ans)puts("First");
       		else puts("Second");
        	return 0;
		}
	}
}