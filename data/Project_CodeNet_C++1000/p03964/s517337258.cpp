#include<iostream>
using namespace std;
int main(void){
    long long n,t,a,T=1LL,A=1LL,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>a;
        m=max((T+t-1LL)/t,(A+a-1LL)/a);
        T=t*m;A=a*m;
    }
    cout<<T+A<<endl;
    return 0;
}