#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

bool Pre[5002][5002],Suf[5002][5002],Ans[5002];
int Data[5005];
int N,K;

template<typename elemType>
inline void Read(elemType &T){
    elemType X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    T=(w?-X:X);
}

int main(){
    Read(N);Read(K);
    for(register int i=1;i<=N;++i)
        Read(Data[i]);
    sort(Data+1,Data+N+1);
    Pre[0][0]=Suf[N+1][0]=true;
    for(register int i=1;i<=N;++i){
        for(register int j=0;j<K;++j){
            Pre[i][j]=Pre[i-1][j];
            Suf[N-i+1][j]=Suf[N-i+2][j];
        }
        for(register int j=0;j<K;++j){
            if(Suf[N-i+2][j] && j+Data[N-i+1]<K) Suf[N-i+1][j+Data[N-i+1]]=true;
            if(Pre[i-1][j] && j+Data[i]<K) Pre[i][j+Data[i]]=true;
        }
    }
    for(register int i=1;i<=N;++i){
        if(Data[i]>=K){Ans[i]=true;continue;}
        int p1=K-1,p2=0;
        bool flag=false;
        while(p1>=0 && p2<K){
            if(!Pre[i-1][p1]){--p1;continue;}
            while(p1+p2<K){
                if(Pre[i-1][p1] && Suf[i+1][p2] && p1+p2+Data[i]>=K){
                    Ans[i]=true;
                    flag=true;
                    break;
                }
                ++p2;
            }
            if(flag) break;
            --p1;
        }
    }
    int Count=0;
    for(register int i=1;i<=N;++i)
        if(!Ans[i]) ++Count;
    printf("%d\n",Count);

    return 0;
}