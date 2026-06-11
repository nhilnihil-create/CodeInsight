/**
*    author:  yuya1234
*    created: 24.06.2020 16:08:27
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,nn,ans;
    cin>>n;

    nn=2;
    while(n>=nn)
    {
        nn*=2;
    }

    cout<<nn/2<<endl;

    return 0;
}