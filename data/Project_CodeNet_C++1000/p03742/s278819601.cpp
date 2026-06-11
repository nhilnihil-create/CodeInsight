#include<cstdio>
#include<algorithm>
using namespace std;
long long X,Y;
int main(){
	scanf("%lld%lld",&X,&Y);
	if(X>Y)swap(X,Y);
	if(X+2>Y)printf("Brown\n");
	else printf("Alice\n"); 
} 