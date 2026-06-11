#include <cstdio>
#include <cctype>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

int n,a[100100];

int getint()
{
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return x;
}

int gcd(int x,int y)
{
    for (int t; t=x%y; x=y,y=t);
    return y;
}

int main()
{
    n=getint();
    repu(i,1,n)
        a[i]=getint();
    for (int i=1; 1; ++i)
    {
        int even=0,odd=0;
        repu(j,1,n)
            (a[j]&1?odd:even)++;
        if (even&1)
        {
            puts(i&1?"First":"Second");
            return 0;
        }
        if (odd>1)
        {
            puts(i&1?"Second":"First");
            return 0;
        }
        repu(j,1,n)
            if (a[j]&1)
            {
                if (a[j]==1)
                {
                    puts(i&1?"Second":"First");
                    return 0;
                }
                --a[j];
                break;
            }
        int d=a[1];
        repu(j,2,n)
            if ((d=gcd(d,a[j]))==1)
                break;
        if (d>1)
            repu(j,1,n)
                a[j]/=d;
    }
    return 0;
}