#include <cstdio>
typedef long long ll;

inline bool Query(ll x)
{
    printf("? %lld\n",x),fflush(stdout);
    char s[10];
    return scanf("%s",s),*s=='Y';
}

int main()
{
    ll X=1000000000;
    while(!Query(X))X/=10;
    if(X==1000000000)for(X=1;!Query(X+1);X*=10);
    else
    {
        int l=X,r=X*10-1;
        while(l<=r)
        {
            int Mid=(l+r)>>1;
            if(Query(Mid*10ll))X=Mid,r=Mid-1;
            else l=Mid+1;
        }
    }
    return printf("! %lld\n",X),fflush(stdout),0;
}
