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
    int n,m,ans=0; cin>>n>>m;
    vector<int> ncnt(100001,0);
    vector<pp> cnt(m,mk(0,0));
    rep(i,n){
        int x; cin>>x;
        ncnt[x]++;
        cnt[x%m].first++;
        if(ncnt[x]%2==0) cnt[x%m].second++;
    }
    rep(i,m/2+1){
        if(i==0 || (m%2==0 && i==m/2)){
            ans+=cnt[i].first/2;
        }
        else{
            if(cnt[i].first>cnt[m-i].first){
                ans+=cnt[m-i].first;
                ans+=min((cnt[i].first-cnt[m-i].first)/2,cnt[i].second);
            }
            else{
                ans+=cnt[i].first;
                ans+=min((cnt[m-i].first-cnt[i].first)/2,cnt[m-i].second);
            }
        }
    }
    cout<<ans<<endl;
}