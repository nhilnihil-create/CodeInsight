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
    int n,ans=0; cin>>n;
    vector<int> a(n,0),b(n,0);
    rep(i,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(al(a));
    set<int> s;
    rep(i,(n+1)/2) s.insert(a[2*i]);
    rep(i,(n+1)/2) if(s.count(b[2*i])==0) ans++;
    cout<<ans<<endl;
}