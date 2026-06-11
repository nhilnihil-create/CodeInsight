#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map> 
#include <set>
#include <ctime> 
#include <queue> 

#define LL long long

using namespace std;

int n;
char str[19] = "9999999999";

char read()
{
	char ret = 0;
	while(ret!='Y' && ret!='N')
		ret=getchar();
	return ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
	//freopen("test_out.txt", "w", stdout);
	#endif
	int cur = 0;
	bool only_one_1 = false;
	while(1)
	{
		int l = 0, r = 9, mid;
		while(l<r)
		{
			mid = l+r>>1;
			if(mid==0 && cur==0) { l = 1; break; }
			if(mid!=-1)	str[cur] = mid+'0';
			else	str[cur] = 0;
			printf("? %s\n", str);
			fflush(stdout);
			char ans = read();
			if(ans=='Y')
				r = mid;
			else
				l = mid+1;
		}
		if(l==1 && cur==0)	only_one_1 = true;
		if(cur!=0 && l!=0)	only_one_1 = false;
		str[cur] = l+'0';
		if(cur==9)	break;
		cur++;
	}
	while(1)
	{
		if(str[cur] != '0')
		{
			str[cur+1] = 0;
			printf("! %s\n", str);
			break;
		}
		LL x = 0;
		for(int i = 0; i < cur; i++)
			x+=str[i]-'0', x*=10;
		x--;
		cout<<"? "<<x<<endl;
		fflush(stdout);
		char ans = read();
		if(!only_one_1)
			if(ans == 'Y')
			{
				str[cur] = '0'; str[cur+1] = 0;
				printf("! %s\n", str);
				break;
			}else
				cur--;
		else
			if(ans == 'N')
			{
				str[cur] = '0'; str[cur+1] = 0;
				printf("! %s\n", str);
				break;
			}else
				cur--;
	}
}