//This solution is not worked out by myself.
#include<cstdio>
long long str[205][2];
long long n,noww=100;
void solve(long long num)
{
	if(num<=1) return ;
	if(num%2) str[++str[0][0]][0]=noww--,solve(num-1);
	else str[++str[0][1]][1]=noww--,solve(num/2);
}
int main ()
{
	scanf("%lld",&n); solve(n+1);
	printf("%lld\n",2*(str[0][0]+str[0][1])); noww=100-str[0][0]-str[0][1]+1;
	for(int i=1;i<=str[0][0];i++) printf("%lld ",str[i][0]);
	for(int i=str[0][1];i;i--) printf("%lld ",str[i][1]);
	for(int i=noww;i<=100;i++) printf("%lld ",1ll*i);
	return 0;
}