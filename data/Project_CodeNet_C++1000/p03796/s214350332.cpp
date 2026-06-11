#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long ans=1;
    int MOD=1e9+7;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}