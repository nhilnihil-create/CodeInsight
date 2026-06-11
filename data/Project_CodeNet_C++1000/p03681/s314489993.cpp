#include<iostream>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    long long ans(1);
    if(abs(n-m)<=1){
        for(int i(1);i<=n;i++){
            ans *= i;
            if(ans>=1000000007)ans %= 1000000007;
        }
        for(int i(1);i<=m;i++){
            ans *= i;
            if(ans>=1000000007)ans %= 1000000007;
        }
        if(n==m){
            ans *= 2;
            if(ans>=1000000007)ans %= 1000000007;
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}