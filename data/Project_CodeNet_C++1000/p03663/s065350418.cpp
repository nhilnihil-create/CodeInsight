#include <bits/stdc++.h>
using namespace std;
char s[5];
inline void cas1()
{int now=2,tp=1;
while(1)
{printf ("? %d\n",now);
fflush(stdout);scanf ("%s",s);
if (s[0]=='Y') {printf ("! %d\n",tp);return;}
now*=10;tp*=10;
}
return;
}
inline bool check(int m)
{printf ("? %lld\n",10ll*((long long)(m)));
fflush(stdout);scanf("%s",s);
if (s[0]=='Y') {return 1;}
return 0;
}
inline void cas2()
{int now=1,ws=0;
int p[11]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
while(1)
{printf ("? %d\n",now);
fflush(stdout);scanf ("%s",s);
if (s[0]=='N') {break;}
ws++;now*=10;
}
int l=p[ws]+1,r=p[ws+1]-1;
while (l<=r)
{int mid=(l+r)>>1;
if (check(mid)) {r=mid-1;}
else {l=mid+1;}
}
printf ("! %d\n",l);
return;
}
int main (){
	printf ("? 1000000000\n");
	fflush(stdout);scanf ("%s",s);
	if (s[0]=='Y') {cas1();}
	else {cas2();}
	return 0;
}