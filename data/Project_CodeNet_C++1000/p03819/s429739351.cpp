#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T& t)
{T f=1;char ch=getchar();t=0;
while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
while(ch>='0'&&ch<='9')t=t*10+ch-'0',ch=getchar();t*=f;}
template <typename T,typename... Args>
inline void read(T& t, Args&... args)
{read(t);read(args...);}
int n,m,L,R;
int sum[100005];
int main()
{
    read(n,m);
//    printf("-- %d %d --",n,m);
    for(int i=1;i<=n;i++)
    {
        read(L,R);
        L--;
//        printf("ok\n");
        for(int l=1,r;l<=L;l=r+1)
        {
            r=min(L/(L/l),R/(R/l));
//            printf("--- %d %d ---\n",l,r);
            if(L/l<R/l)
            {
                sum[l]++;
                sum[r+1]--;
            }
        }
        sum[L+1]++;
        sum[R+1]--;
    }
    for(int i=1;i<=m;i++)printf("%d\n",sum[i]+=sum[i-1]);
}