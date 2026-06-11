#include <cstdio>
#include <cctype>
#include <algorithm>
#include <functional>
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

int main()
{
    n=getint();
    repu(i,1,n)
        a[i]=getint();
    sort(a+1,a+1+n,greater<int>());
    repu(i,1,n)
    {
        if (a[i]==i)
        {
            int j=i;
            for (; j<n && a[j+1]==a[i]; ++j);
            puts((j-i)&1?"First":"Second");
            return 0;
        }
        if (a[i+1]==i)
        {
            int j=i+1;
            for (; j<n && a[j+1]==i; ++j);
            puts(((j-i)&1) || ((a[i]-i)&1)?"First":"Second");
            return 0;
        }
        if (a[i+1]<i)
        {
            puts((a[i]-i)&1?"First":"Second");
            return 0;
        }
    }
    return 0;
}