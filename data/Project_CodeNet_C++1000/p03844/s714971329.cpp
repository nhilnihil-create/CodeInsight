#include <cstdio>
using namespace std;

char c;
int a , b;
 
int main () {
	scanf("%d %c %d",&a,&c,&b);
	if (c == '+') printf("%d\n",a+b);
	else if (c == '-') {
		if (a > b) printf("%d\n",a-b);
		else if (b > a) printf("-%d\n",b-a);
	}
}