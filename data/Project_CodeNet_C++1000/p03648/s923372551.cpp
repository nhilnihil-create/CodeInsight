#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}



signed main(){
    int K;cin>>K;


    vint ans(50,49-K+K/50*51);

    for(int i=0;i<K%50;i++)ans[i]+=51;

    cout<<50<<endl;
    rep(i,50){
        if(i)cout<<" ";
        cout<<ans[i];
    }cout<<endl;
    return 0;
}
