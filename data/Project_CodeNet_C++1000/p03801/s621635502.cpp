#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
int main(){
    ll N;cin>>N;
    vector<pair<ll,int>> a(N);
    REP(i, N){ 
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(All(a),[](const pair<ll,int> &a,const pair<ll,int> &b){
        if(a.first!=b.first) return a.first>b.first;
        else return a.second>b.second;
    });
    vector<ll> ans(N,0);
    ll j=1;
    int m=N;
    while(j<N){
        m=min(m,a[j-1].second);
        if(a[j].first==a[0].first) j++;
        else{
            ans[m]+=j*(a[0].first-a[j].first);
            a[0].first=a[j].first;
        }
        
    }
    ans[0]+=N*a[0].first;
    REP(i,N) cout<<ans[i]<<endl;
}