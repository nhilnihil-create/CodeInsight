#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int N; cin>>N;
    vector<ll> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int ans=0;
    int now=0;
    for(int i=1;i<N;i++){
        if(A[i]>A[i-1]){
            if(now==1){
                ans++;
                now=0;
                continue;
            }
            now=-1;
        }
        else if(A[i]<A[i-1]){
            if(now==-1){
                ans++;
                now=0;
                continue;
            }
            now=1;
        }
    }
    cout<<ans+1;
    return 0;
}