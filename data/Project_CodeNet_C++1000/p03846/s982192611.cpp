#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


long long modpow(long long a, long long n, long long mod){
    long long res=1;
    while(n>0){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int mod=1e9+7;
    for(int i=0;i<n;i++)cin>>a[i];
    bool flag=true;
    sort(a,a+n);
    if(n%2==0){
        for(int i=0;2*i<n;i++){
            if(a[2*i]!=2*i+1||a[2*i+1]!=2*i+1)flag=false;
        }
    }else if(n%2!=0){
        if(a[0]!=0)flag=false;
        for(int i=1;2*i<n;i++){
            if(a[2*i-1]!=2*i||a[2*i]!=2*i)flag=false;
        }
    }
    if(flag==false)cout<<0<<endl;
    else{
        cout<<modpow(2,n/2,mod)<<endl;
    }
    return 0;
}