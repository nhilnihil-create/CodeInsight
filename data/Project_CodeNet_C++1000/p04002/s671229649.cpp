#include <map>
#include <cstdio>
#include <iostream>
typedef long long ll;

int W,H,N;
ll Cnt[15];
std::map<std::pair<int,int>,bool> G,P;

int main()
{
    scanf("%d%d%d",&W,&H,&N),Cnt[0]=ll(W-2)*(H-2);
    for(int i=1,x,y;i<=N;++i)
    {
        scanf("%d%d",&x,&y),G[std::make_pair(x,y)]=true;
        for(int xs=x-2;xs<=x;++xs)
            for(int ys=y-2;ys<=y;++ys)
                if(xs>=1&&xs+2<=W&&ys>=1&&ys+2<=H)
                    P[std::make_pair(xs,ys)]=true;
    }
    for(auto i:P)
    {
        int Nc=0;
        for(int j=0;j<=2;++j)
            for(int k=0;k<=2;++k)
                if(G.count(std::make_pair(i.first.first+j,i.first.second+k)))
                    ++Nc;
        ++Cnt[Nc],--Cnt[0];
    }
    for(int i=0;i<=9;++i)std::cout<<Cnt[i]<<std::endl;
    return 0;
}