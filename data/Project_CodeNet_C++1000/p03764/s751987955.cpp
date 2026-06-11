#include <iostream>
using namespace std;
long long mod=1e9+7;
int main(void){
    long long n,m,ans1=0,ans2=0,a;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        ans1+=(2*i-n+1)*a;
    }
    for(int i=0;i<m;i++){
        cin>>a;
        ans2+=(2*i-m+1)*a;
    }
    cout<<((ans1%mod)*(ans2%mod))%mod<<endl;
}