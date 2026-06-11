#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    long long A[N+1];
    for(long long i=1;i<=N;i++){
        cin>>A[i];
    }
    long long ans=0;
    vector<long long>P(N+1);
    for(long long i=1;i<=N;i++){
        if(A[A[i]]==i){
            ans++;
        }
    }
    ans/=2;
    cout<<ans<<endl;
    return 0;
}
