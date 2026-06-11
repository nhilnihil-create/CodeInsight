#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define i_cin(X) scanf("%d", &X)
#define i_cin2(X,Y) scanf("%d %d",&X,&Y)
#define i_cin3(X,Y,Z) scanf("%d %d %d",&X,&Y,&Z)
#define l_cin(X) scanf("%ld",&X)
#define s_cin(X) scanf("%s",&X)

#define  i_cout(X) printf("%d\n",X)
#define  l_cout(X) printf("%ld\n",X)
#define  s_cout(X) printf("%s\n",X)
#define  ll_cout(X) printf("%lld\n",X)

int main(void) {
	char  str[4];
	s_cin(str);
	if(str[0]==str[2])
		 s_cout("Yes");
	else s_cout("No");
	return 0;
}
