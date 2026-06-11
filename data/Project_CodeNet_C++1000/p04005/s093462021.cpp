#include<cstdio>
#include<algorithm> 
using namespace std;

long long A,B,C,mx,mn;
int main(){
	scanf("%lld%lld%lld",&A,&B,&C); 
	if(A%2==0||B%2==0||C%2==0)	mn=0;
	else{
		mx=max(A,B);mx=max(mx,C);
		if(mx==A) mn=B*C;
		else if(mx==B)  mn=A*C;
		else mn=A*B;
	}
	printf("%lld\n",mn);
	return 0;
} 