#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int64_t> A(N);
    rep(n,0,N) cin>>A.at(n);

    int64_t ans=0;
    rep(i,0,N){
        ans+=A.at(i)/2;
        if(A.at(i)%2){
            if(i+1<N && A.at(i+1)>0){
                ans++;
                A.at(i+1)--;
            }
        }
    }

    cout<<ans<<endl;
}