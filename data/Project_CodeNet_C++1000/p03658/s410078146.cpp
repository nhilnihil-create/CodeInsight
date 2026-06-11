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
    int n,k; cin>>n>>k;
    vector<int> l(n,0);
    rep(i,n) cin>>l[i];
    sort(al(l)); reverse(al(l));
    int ans=0;
    rep(i,k) ans+=l[i];
    cout<<ans<<endl;
}
