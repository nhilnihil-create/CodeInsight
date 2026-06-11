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

    vint latte;
    while(K){
        if(K%2&&K>=3){
            K=(K-1)/2;
            latte.pb(0);
        }
        else{
            K--;
            latte.pb(1);
        }
    }

    deque<int>v;

    for(int i=latte.size()-1;i>=0;i--){
        if(latte[i])v.pb(i+1);
        else v.push_front(i+1);
    }

    for(int i=100;i>0;i--)v.push_front(i);
    cout<<v.size()<<endl;
    rep(i,v.size()){
        if(i)cout<<" ";

        cout<<v[i];
    }
    cout<<endl;
    return 0;
}
