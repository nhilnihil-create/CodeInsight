#include<bits/stdc++.h>
#define LL long long
#define R register int
using namespace std;
const int YL=1e9+7;
inline void M(R&x){if(x>=YL)x-=YL;}
int main(){
    R n;cin>>n;
    R f2=0,f1=n,f=(LL)n*n%YL,t=(LL)(n-1)*(n-1)%YL,s=0;
    for(R i=n-2;i>0;--i)
        M(s+=f2),f2=f1,f1=f,M(f+=t),M(f+=s+i+1);
    return cout<<f<<endl,0;
}