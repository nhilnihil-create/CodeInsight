#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
#define TP int
inline TP read(){
    char c=getchar();TP x=0;bool f=0;
    while(!isdigit(c))f^=!(c^45),c=getchar();
    while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f)x=-x;return x;
}
int dic[12093];
char s[1000010];
int main()
{
	dic['b']=0;dic['p']=1;dic['d']=2;dic['q']=3;
	cin>>(s+1);
    for(int l=strlen(s+1),i=1;i<=(l>>1)+1;i++)
    {
        if(dic[s[i]]!=((dic[s[l-i+1]]+2)%4))return puts("No"),0;
    }puts("Yes");
    return 0;
}
