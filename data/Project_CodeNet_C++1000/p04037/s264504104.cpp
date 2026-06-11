/*


*/
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <functional>
#define MAXIN 300000
#define gc() (SS==TT&&(TT=(SS=IN)+fread(IN,1,MAXIN,stdin),SS==TT)?EOF:*SS++)
typedef long long LL;
const int N=1e5+5;

int A[N];
char IN[MAXIN],*SS=IN,*TT=IN;

inline int read()
{
	int now=0;register char c=gc();
	for(;!isdigit(c);c=gc());
	for(;isdigit(c);now=now*10+c-48,c=gc());
	return now;
}

int main()
{
	const int n=read();
	for(int i=1; i<=n; ++i) A[i]=read();
	std::sort(A+1,A+1+n,std::greater<int>());
	for(int i=1; i<=n; ++i)
		if(i+1>A[i+1])
		{
			int ans=0;
			for(int j=i+1; A[j]==i; ++j) ans^=1;
			ans|=A[i]-i&1;
			puts(ans?"First":"Second");
			return 0;
		}

	return 0;
}