#include <cstdio>
#include <cstring>
#include <deque>
#define LL long long
using namespace std;

LL n;
int d[210];
deque<int> S;

int main(){
	scanf("%lld",&n);
	int m=0;
	while(n){
		if(n&1){
			n=(n-1)/2;
			d[++m]=1;
		}else{
			n--;
			d[++m]=0;
		}
	}
	for(int i=m;i>=1;i--)
		if(d[i]) S.push_back(m-i+1);
		else S.push_front(m-i+1);
	printf("%d\n",m<<1);
	for(int i=0;i<m;i++)
		printf("%d ",S[i]);
	for(int i=1;i<=m;i++)
		printf("%d ",i);
}
