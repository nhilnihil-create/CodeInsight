#include<cstdio>
using namespace std;
int Q,s,x;
int main(){
	scanf("%*d%d",&Q);
	Q*=2;
	while(Q--){
		scanf("%d",&x);
		s^=x;
	}
	puts(s?"NO":"YES");
	return 0;
}
