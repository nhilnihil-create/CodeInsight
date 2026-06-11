#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

long long int gcd(long long int a,long long int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}
long long int fac(long long int n){
    if(n==0){
        return 1;
    }
    else{
        return n*(fac(n-1))%1000000007;
    } 
}

int main(){
    long long int a,b;
    cin>>a>>b;
    if(a-b>1||a-b<-1){
        cout<<0<<endl;
    }
    if(a-b==1||a-b==-1){
        cout<<(fac(a)*fac(b))%1000000007<<endl;
    }
    if(a==b){
        cout<<(2*fac(a)*fac(b))%1000000007<<endl;
    }


    return 0;
}