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

    sort(ToEnd(A));
    vector<int64_t> sumA(N+1,0);
    rep(n,1,N+1) sumA.at(n)=sumA.at(n-1)+A.at(n-1);

    int ans=0;
    rep(n,0,N){
        int64_t sz=sumA.at(n+1);
        auto preItr=next(A.begin(),n);

        while(1){
            auto itr=upper_bound(ToEnd(A),sz*2);
            if(itr==A.end()){
                ans=N-n;
                break;
            }
            if(preItr==itr) break;

            sz=sumA.at(distance(A.begin(),itr));
            preItr=itr;
        }

        if(ans) break;
    }

    cout<<ans<<endl;
}