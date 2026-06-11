#include<cstdio>
#include<algorithm>
using namespace std;
int a, b;
int main()
{
	scanf("%d%d",&a, &b);
	if(a == 0 || b == 0){
		if(a > b) printf("%d\n",a-b+1);
		else printf("%d\n",b-a);
	}else if(a > 0 && b > 0){
		if(a < b) printf("%d\n",b-a);
		else printf("%d\n",a-b+2);
	}else if(a > 0 && b < 0 || a < 0 && b > 0){
	    printf("%d\n",abs(abs(a)-abs(b))+1);
	}else{
	    if(a == b) printf("0\n");
		else if(a > b) printf("%d\n",abs(-a+b)+2);
		else printf("%d\n",-a+b);
	}
	return 0;
}