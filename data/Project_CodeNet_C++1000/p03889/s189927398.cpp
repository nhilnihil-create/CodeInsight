#include<bits/stdc++.h>
using namespace std;
int main()
{char a[100100],b[100100];
 cin>>a;
 strcpy(b,a);
 for(int i=0;i<strlen(b);i++)
    {if(b[i]=='b') b[i]='d';
     else if(b[i]=='p') b[i]='q';
     else if(b[i]=='q') b[i]='p';
     else if(b[i]=='d') b[i]='b';
	}
 for(int i=0;i<strlen(a);i++)
    if(a[i]!=b[strlen(a)-i-1])
      {printf("No\n");
       return 0;
	  }
 printf("Yes\n");
 return 0;
}