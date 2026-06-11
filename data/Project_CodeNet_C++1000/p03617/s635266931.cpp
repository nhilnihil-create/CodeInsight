#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q,h,s,d;
    long long n;
    cin>>q>>h>>s>>d>>n;

    long long sum=0;
    if(d<2*s && d<4*h && d<8*q){
        sum+=(n/2)*d;
        n%=2;
    }
    if(s<2*h && s<4*q){
        sum+=n*s;
        n=0;
    }
    if(h<2*q){
        sum+=2*n*h;
        n=0;
    }
    {
        sum+=4*n*q;
        n=0;
    }

    cout<<sum<<endl;
}