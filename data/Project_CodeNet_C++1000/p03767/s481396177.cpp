#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;cin>>N;
    vector<long long>A(3*N);
    for(long long i=0;i<3*N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    long long ans=0;
    for(long long i=3*N-2;i>=N;i-=2){
        ans+=A[i];
    }
    cout<<ans<<endl;
    return 0;
}