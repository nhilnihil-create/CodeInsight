#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=min(b,d)-max(a,c);
    if(ans<=0){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}