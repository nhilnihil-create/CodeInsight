#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t A,B,C; cin>>A>>B>>C;

    int64_t ans=0;
    if(A%2 && B%2 && C%2){
        vector<int64_t> v{A,B,C};
        sort(ToEnd(v));
        ans=v.at(0)*v.at(1);
    }else ans=0;

    cout<<ans<<endl;
}