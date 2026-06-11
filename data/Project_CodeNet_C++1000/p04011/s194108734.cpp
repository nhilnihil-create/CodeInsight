#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld double
#define ff first
#define ss second
int main(){
	int n,k,x,y;
	scanf("%d%d%d%d",&n,&k,&x,&y);
	if(n<=k){
		printf("%d\n",n*x);
	}
	else printf("%d\n",k*x+(n-k)*y);
	return 0;
}
