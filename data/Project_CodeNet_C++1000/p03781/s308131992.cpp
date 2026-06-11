#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define LL long long
LL N;

int main(){
    cin>>N;
    if(N==0){cout<<0<<endl;return 0;}
    LL L=1,R=N,Ans=0;
    while(L<=R){
        LL mid=(L+R)>>1;
        if(mid*(mid+1LL)>=2LL*N){Ans=mid;R=mid-1;}
        else L=mid+1;
    }
    cout<<Ans<<endl;
    
    return 0;
}