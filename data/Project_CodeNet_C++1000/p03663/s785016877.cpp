#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define maxn 500300
using namespace std;
inline void read(int &x) {
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}
inline void write(int x) {
    static const int maxlen = 100;
    static char s[maxlen];
    if (x < 0) {   putchar('-'); x = -x;}
    if (!x) { putchar('0'); return; }
    int len = 0; for (; x; x /= 10) s[len++] = x % 10 + '0';
    for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}


int a[10000];
int len=13;
char s[1000];
char sout[1000];

bool check1(int x){
a[1]=x;
for (int i=1;i<=len;i++)
    sout[i-1]=a[i]+'0';
sout[len]='\0';
cout<<"? "<<sout<<endl;
scanf("%s",s);
if (s[0]=='Y')
    return 1;
else
    return 0;
//system("pause");
cout.flush();
}


bool checklen(int x){
len=x;
for (int i=1;i<=len;i++)
    sout[i-1]=a[i]+'0';
sout[len]='\0';
cout<<"? "<<sout<<endl;
scanf("%s",s);
if (s[0]=='Y')
    return 1;
else
    return 0;
cout.flush();
}

void doitlen9(){
    int l=2,r=10;
    a[ 1 ]= 1;
    for (int i = 2 ; i <= 11 ;i ++ )
        a[i]=9;
    int tmp=1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (checklen(mid))
        {
            l=mid+1;
            tmp=mid;
        }
        else
            r=mid-1;
    }
    len=tmp;
    a[ 1 ]=9;
}


void doitlen(){
    int l=2,r=10;
    if (a[ 1 ]!= 9)
        a[ 1 ]++;
    else
    {
        doitlen9();
        return ;
    }
    for (int i = 2 ; i <= 11 ;i ++ )
        a[i]=9;
    int tmp=1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (checklen(mid))
        {
            r=mid-1;
            tmp=mid;
        }
        else
            l=mid+1;
    }
    len=tmp;
    a[ 1 ]--;
}



bool checkx(int x,int y){
a[x]=y;
for (int i=1;i<=len+1;i++)
    sout[i-1]=a[i]+'0';
sout[len+1]='\0';
cout<<"? "<<sout<<endl;
scanf("%s",s);
if (s[0]=='Y')
    return 1;
else
    return 0;
cout.flush();
}


void doitx(int x){
    int l=0,r=9;
    int tmp=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (checkx(x,mid))
        {
            r=mid-1;
            tmp=mid;
        }
        else
            l=mid+1;
    }
    a[x]=tmp;
}



int main(){
    int tmp=1;
    int l=1,r=9;
    for (int i=1;i<=len;i++)
        a[i]=9;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check1(mid))
            {
                r=mid-1;
                tmp=mid;
            }
        else
            l=mid+1;
    }
    a[1]=tmp;
    doitlen();
    if (len==2)
        {
            if (tmp==1)
                {
                    a[1]=9;
                    if (checklen(1))
                    {
                        a[1]=1;len=1;
                        for (int i=1;i<=len;i++)
                            sout[i-1]=a[i]+'0';
                        sout[len]='\0';
                        cout<<"! "<<sout<<endl;
                        cout.flush();
                        return 0;
                    }
                    else
                    {
                        a[1]=1;
                        len=2;
                    }
                }
            else
            {
            a[1]=1; a[2]=0;
            if (!checklen(2))
                {
                    a[1]=tmp;len=1;
                    for (int i=1;i<=len;i++)
                        sout[i-1]=a[i]+'0';
                    sout[len]='\0';
                    cout<<"! "<<sout<<endl;
                    cout.flush();
                    return 0;
                }
            else
                {
                    a[1]=tmp;
                    len=2;
                }
            }
        }
    for (int i=2;i<=len+1;i++)
        a[i]=9;
    for (int i=2;i<=len;i++)
        doitx(i);
    for (int i=1;i<=len;i++)
        sout[i-1]=a[i]+'0';
    sout[len]='\0';
    cout<<"! "<<sout<<endl;
    cout.flush();
    return 0;
}
