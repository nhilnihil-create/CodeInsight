#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    uint64_t ans=0;
    while(1){
        if(a%2 || b%2 || c%2) break;

        int _a,_b,_c;
        _a=(b+c)/2; _b=(c+a)/2; _c=(a+b)/2;
        if(a==_a && b==_b && c==_c){
            cout<<-1<<endl;
            return 0;
        }

        a=_a; b=_b; c=_c;
        ans++;
    }

    cout<<ans<<endl;
}