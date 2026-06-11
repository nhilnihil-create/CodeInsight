#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int N; cin>>N;
    vector<ll> A(N,0);
    vector<ll> B(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    ll ans=0;
    for(int i=N-1;i>=0;i--){
        A[i]+=ans;
        if(A[i]%B[i]!=0){
            int tmp=(A[i]/B[i]+1)*B[i]-A[i];
            A[i]+=tmp;
            ans+=tmp;
        }
    }
    cout<<ans;
    return 0;
}