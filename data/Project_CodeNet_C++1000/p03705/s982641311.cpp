#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,A,B; cin>>N>>A>>B;

    int64_t ans;
    if(N>=2){
        if(B>=A) ans=(N-2)*(B-A)+1;
        else ans=0;
    }else{
        if(A==B) ans=1;
        else ans=0;
    }

    cout<<ans<<endl;
}