/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long A,B;
int main(){
	scanf("%lld%lld",&A,&B);
	printf("%s\n",(max(A,B)-min(A,B))>1? "Alice":"Brown");
	return 0;
}