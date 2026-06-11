/**********

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*********/

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}

long long primechk[10000];

void preprocess(long long N){
    long long i,j;
    for(i=2;i<=N;i++){
        primechk[i]=1;
    }
    for(i=2;i<=N;i++){
        if(primechk[i]==1){
            for(j=2;i*j<=N;j++){primechk[i*j]=0;}
        }
    }
}

long long Binexpo(long long a,long long b){
    if(b==0)
        return 1;
    long long res=Binexpo(a,b/2);
    if(b%2){return res*res*a;}
    else{return res*res;}
}
long long Pwr(long long a,long long b,long long m){
    a%=m;
    long long res=1;
    while(b>0){
        if(b%2){res=res*a%m;}
        a=a*a%m;
        b>>=1;
    }
    return res;
}
int main()
{   long long a,b,c,d,e,f,g,h,i,j,k,x,y,z,sum,cnt=0,n;
    cin>>n;
    long long arr[n];
    for(i=0;i<n;i++){arr[i]=0;}
    if(n%2){
        for(i=0;i<n;i++){cin>>x;arr[x]++;}
        for(i=1;i<=n/2;i++){if(arr[2*i]==2){cnt++;}else{cnt*=0;break;}}
        if(arr[0]==1){cnt++;}else{cnt*=0;}
        if(cnt!=0){cout<<Pwr(2,n/2,1000000007);}else{cout<<0;}
    }
    else{
       for(i=0;i<n;i++){cin>>x;arr[x]++;}
        for(i=0;i<n/2;i++){if(arr[2*i+1]==2){cnt++;}else{cnt*=0;break;}}
        if(arr[0]!=0){cnt*=0;}
        if(cnt!=0){cout<<Pwr(2,n/2,1000000007);}else{cout<<0;}
    }

    return 0;
}