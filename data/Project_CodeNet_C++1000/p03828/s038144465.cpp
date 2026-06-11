#include<iostream>
#include<algorithm>
#include<cmath>
#define mod 1000000007
using namespace std;
long long int seive(long long int n){
    int i,j;
    long long int prime[1001];
    long long int sqr=sqrt(1000);
    for(i=0;i<=1000;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for(i=2;i<=sqr;i++){
        if(prime[i]==1){
            for(j=2;i*j<=1000;j++){
                 prime[i*j]=0;
            }
        }
    }
//    for(i=0;i<=1000;i++){
//        if(prime[i]==1) cout<<i<<" ";
//    }
//    cout<<endl;
    long long int num;
    for(j=2;j<=n;j++){
        num=j;
        for(i=2;i<=1000;i++){
            if(prime[i]>=1){
                while(num%i==0){
                    num/=i;
                    prime[i]++;
                }
            }
        }
    }
//    for(i=0;i<=1000;i++){
//        if(prime[i]>1) cout<<i<<"->"<<prime[i]<<endl;
//    }
//    cout<<endl;
    long long int prod=1;
    for(i=0;i<=1000;i++){
        if(prime[i]>1){
            prod=(prod*prime[i])%mod;
        }
    }
    return prod;
}
int main()
{
    long long int n;
    cin>>n;
    cout<<seive(n)<<endl;
}

