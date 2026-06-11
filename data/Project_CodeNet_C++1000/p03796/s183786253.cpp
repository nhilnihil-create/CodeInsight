#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    long long ans=1;
    for(long long i=1;i<=N;i++){
        ans*=i;
        ans%=1000000007;
    }
    cout<<ans<<endl;
}
