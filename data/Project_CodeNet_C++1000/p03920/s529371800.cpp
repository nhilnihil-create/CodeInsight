#include <iostream>
using namespace std;
int main(void){
    long long n,l=0,r;
    cin>>n;
    r=n;
    while(l+1<r){
        long long m=(l+r)/2;
        if(m*(m+1)/2<n){
            l=m;
        }else{
            r=m;
        }
    }
    l=r*(r+1)/2-n;
    for(int i=1;i<=r;i++){
        if(i!=l){
            cout<<i<<endl;
        }
    }
    
}
