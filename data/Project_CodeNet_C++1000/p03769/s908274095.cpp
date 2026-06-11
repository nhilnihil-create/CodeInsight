#include <iostream>
#include <cstdio>
using namespace std;
 
int p[110], q[110], cnt;
long long N;
     
void solve(long long n){
	if(n<=1)	return;
   	if(n&1){
   		q[++q[0]]=cnt++;
   		solve(n-1);
   	}else{
   		p[++p[0]]=cnt++;
   		solve(n>>1);
 	}
}
    
int main(){
  	scanf("%lld", &N);
  	solve(N+1);
  	printf("%d\n", cnt*2);
  	for(int i=1; i<=q[0]; i++)	printf("%d ", cnt-q[i]);
  	for(int i=p[0]; i; i--)		printf("%d ", cnt-p[i]);
   	for(int i=1; i<=cnt; i++)	printf("%d ", i);
 	return 0;
}