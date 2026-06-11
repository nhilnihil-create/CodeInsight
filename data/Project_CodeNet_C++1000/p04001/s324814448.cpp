#include<iostream>
#include<bitset>

using namespace std;

int func(long long n){
    int cnt=0;
    while(n>0){
        ++cnt;
        n/=10;
    }
    return cnt;
}

long long func2(int n){
    long long t=1;
    for(int i=0;i<n;++i){
        t*=10;
    }
    return t;
}

int main(){
    long long s;
    cin>>s;

    int n=func(s);
    long long ans=0;
    for(int bit=0;bit<(1<<(n-1));++bit){
        long long temp=s;
        for(int i=n-2;i>=0;--i){
            if(bit&(1<<i)){
                long long d=func2(i+1);
                ans+=temp/d;
                temp%=d;
            }
        }
        ans+=temp;
    }

    cout<<ans<<endl;
}