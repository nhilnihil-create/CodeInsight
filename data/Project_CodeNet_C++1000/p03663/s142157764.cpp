#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	char s[2];
	int now,k=1;
	for(now=1;now<=10;now++,k*=10)
	{
		printf("? %d\n",k);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='N')break;
	}
	now--;
	if(now==10)
	{
		k=2;
		for(now=1;now<=10;now++,k*=10)
		{
			printf("? %d\n",k);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y'){printf("! %d",k/2);fflush(stdout);return 0;}
		}
	}
	else
	{
		int l=k/10+1,r=k-1;
		while(l<=r)
		{
			if(l==r){printf("! %d",l);fflush(stdout);return 0;}
			if(l==r-1)
			{
				printf("? %lld\n",(long long)l*10);
				fflush(stdout);
				scanf("%s",s);
				if(s[0]=='Y'){printf("! %d",l);fflush(stdout);return 0;}
				else {printf("! %d",r);fflush(stdout);return 0;}
			}
			int mid=l+r>>1;
			printf("? %lld\n",(long long)mid*10);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')r=mid;
			else l=mid+1;
		}
	}
	return 0;
}
//1.控制字典序一定小  1,10,100...， 来确定数字位数或是不是10的次幂
//2.找出位数后，控制数字一定大， 二分ans，给交互库ans*10，比较字典序来确定数字 