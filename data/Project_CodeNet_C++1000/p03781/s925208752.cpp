#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL; 
int N;
int main(){
	scanf("%d",&N);
	for(LL i = 1;i;i++){
		LL x = (i+1)*i>>1;
		if(x >= N){
			printf("%lld\n",i);
			break;
		}
	}
	return 0;
} 