#include <stdio.h>


int main()
{

int a, b, x, xtoa,xtob;

scanf("%d %d %d",&x, &a, &b);


		xtoa=x-a;
		if(xtoa<0){
			xtoa=xtoa*-1;
		}
		xtob=x-b;
		if(xtob<0){
			xtob=xtob*-1;
		}

	if(xtoa>xtob)
	{
		printf("B");
	}
	else if(xtoa<xtob) {
	
		printf("A");
	}

return 0;
}

