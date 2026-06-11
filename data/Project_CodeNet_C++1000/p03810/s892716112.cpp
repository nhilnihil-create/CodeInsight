/*


*/
#include <cstdio>
#include <cctype>
#include <algorithm>
#define MAXIN 300000
#define gc() (SS==TT&&(TT=(SS=IN)+fread(IN,1,MAXIN,stdin),SS==TT)?EOF:*SS++)
typedef long long LL;
const int N=1e5+5;

int n,A[N];
char IN[MAXIN],*SS=IN,*TT=IN;

inline int read()
{
	int now=0;register char c=gc();
	for(;!isdigit(c);c=gc());
	for(;isdigit(c);now=now*10+c-48,c=gc());
	return now;
}
bool DFS(bool now)
{
	int s=0,fg=0;
	for(int i=1; i<=n; ++i) A[i]==1&&(fg=1), s+=A[i]&1;
	if((n-s)&1) return now;
	if(fg||s>1) return now^1;
	for(int i=1; i<=n; ++i)
		if(A[i]&1) {--A[i]; break;}
	int g=A[1];
	for(int i=2; i<=n; ++i) g=std::__gcd(g,A[i]);
	for(int i=1; i<=n; ++i) A[i]/=g;
	return DFS(now^1);
}

int main()
{
	const int n=read(); ::n=n;
	for(int i=1; i<=n; ++i) A[i]=read();
	puts(DFS(1)?"First":"Second");

	return 0;
}