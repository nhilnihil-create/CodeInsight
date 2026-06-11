#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
char str1[maxn];
char str2[maxn];
int n;
int main()
{scanf("%d",&n);
    scanf("%s",str1);



    for(int k=0; k<4; k++)
    {
        int flag=0;
        memset(str2,0,sizeof(str2));
        if(k==0)
        {
            str2[0]='S';
            str2[1]='S';
        }
        else if(k==1)
        {
            str2[0]='W';
            str2[1]='W';
        }
        else if(k==2)
        {
            str2[0]='S';
                    str2[1]='W';
        }
        else if(k==3)
        {
            str2[0]='W';
            str2[1]='S';
        }
        for(int i=1; i<n-1; i++)
        {

            if(str1[i]=='o')
            {
                if(str2[i]=='S')
                {
                    if(str2[i-1]=='S')
                        str2[i+1]='S';


                    else if(str2[i-1]=='W')
                        str2[i+1]='W';

                }
                else if(str2[i]=='W')
                {
                    if(str2[i-1]=='S')
                        str2[i+1]='W';
                    else if(str2[i-1]=='W')
                        str2[i+1]='S';
                }
            }
            else if(str1[i]=='x')
            {
                if(str2[i]=='S')
                {
                    if(str2[i-1]=='S')
                        str2[i+1]='W';


                    else if(str2[i-1]=='W')
                        str2[i+1]='S';

                }
                else if(str2[i]=='W')
                {
                    if(str2[i-1]=='S')
                        str2[i+1]='S';
                    else if(str2[i-1]=='W')
                        str2[i+1]='W';
                }
            }
        }
        if(str1[0]=='o')
        {
            if(str2[0]=='S')
            {
                if(str2[n-1]!=str2[1])
                    flag=1;

            }
            else if(str2[0]=='W')
            {
                if(str2[n-1]==str2[1])
                    flag=1;
            }
        }
        else if(str1[0]=='x')
        {
            if(str2[0]=='S')
            {
                if(str2[n-1]==str2[1])
                    flag=1;
            }
            else if(str2[0]=='W')
            {
                if(str2[n-1]!=str2[1])
                    flag=1;
            }

        }
        if(str1[n-1]=='o')
        {
            if(str2[n-1]=='S')
            {
                if(str2[0]!=str2[n-2])
                    flag=1;

            }
            else if(str2[n-1]=='W')
            {
                if(str2[0]==str2[n-2])
                    flag=1;
            }
        }
        else if(str1[n-1]=='x')
        {
            if(str2[n-1]=='S')
            {
                if(str2[0]==str2[n-2])
                    flag=1;
            }
            else if(str2[n-1]=='W')
            {
                if(str2[0]!=str2[n-2])
                    flag=1;
            }

        }
        if(!flag)
        {
            for(int i=0; i<n; i++)
                printf("%c",str2[i]);
            printf("\n");
            return 0;
        }

    }
    printf("-1\n");

    return 0;
}


