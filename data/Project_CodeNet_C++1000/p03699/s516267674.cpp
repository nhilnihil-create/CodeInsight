//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m=inf,ans=0; cin>>n;
    rep(i,n){
        int s; cin>>s;
        ans+=s;
        if(s%10) m=min(m,s);
    }
    if(ans%10) cout<<ans<<endl;
    else{
        if(m==inf) m=ans;
        cout<<ans-m<<endl;
    }
}
