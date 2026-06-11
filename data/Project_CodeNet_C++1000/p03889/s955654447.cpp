#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void RI(T &x)
{
    x=0;bool f=0;char c=getchar();
    while(c<'0'||c>'9'){f|=(c=='-');c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    if(f) x=-x;
}
char A[1000005],B[1000005];
int N;

int main()
{
    scanf("%s",A);N=strlen(A);
    for(int i=0;i<N;++i)
        B[i]=A[N-i-1];
    for(int i=0;i<N;++i)
    {
        if(B[i]=='b') B[i]='d';
        else if(B[i]=='d') B[i]='b';
        else if(B[i]=='p') B[i]='q';
        else if(B[i]=='q') B[i]='p';
    }
    bool f=1;
    for(int i=0;i<N;++i)
        f&=A[i]==B[i];
    if(f) printf("Yes\n");
    else printf("No\n");
    return 0;
}