#include<cstdio>
using namespace std;

int main(){
	int a,b,c;
  	while(~scanf("%d%d%d",&a,&b,&c)){
    	if(a+b==c||a+c==b||b+c==a) puts("Yes");
      	else puts("No");
    }
    return 0;
}