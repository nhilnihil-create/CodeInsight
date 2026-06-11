#include<iostream>
using namespace std;
const int N=101;
int n,x,c[N],M;
int main()
{
	cin>>n;
	while(n--&&cin>>x)
		c[x]++,M=max(M,x);
	if(M%2==0)
		c[M/2]++;
	for(int i=1;i<N;i++)
		if((i<M/2&&c[i])||(i==(M+1)/2&&c[i]!=2)||(M/2<i&&i<=M&&c[i]<2))
		{
			cout<<"Impossible";
			return 0;
		}
	cout<<"Possible";
	return 0;
}