#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    bitset<4> drc(0);
    for(auto s:S){
        if(s=='E') drc.set(0);
        if(s=='W') drc.set(1);
        if(s=='S') drc.set(2);
        if(s=='N') drc.set(3);
    }

    string ans="Yes";
    if(drc.test(0)^drc.test(1) || drc.test(2)^drc.test(3)) ans="No";
    cout<<ans<<endl;
}