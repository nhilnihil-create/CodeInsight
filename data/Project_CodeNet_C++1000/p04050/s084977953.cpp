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

int N,M;
int A[111];


signed main(){
    cin>>N>>M;
    rep(i,M)cin>>A[i];

    vint o,e;
    rep(i,M){
        if(A[i]%2)o.pb(A[i]);
        else e.pb(A[i]);
    }

    if(o.size()>2){
        cout<<"Impossible"<<endl;
        return 0;
    }

    if(o.size()==0){
        rep(i,e.size()){
            if(i)cout<<" ";
            cout<<e[i];
        }
        cout<<endl;
        cout<<e.size()+1<<endl;
        rep(i,e.size()){
            if(i)cout<<" ";
            if(i==0)cout<<e[i]-1;
            else cout<<e[i];
        }
        cout<<" "<<1<<endl;

    }
    else if(o.size()==1){
        cout<<o[0];
        rep(i,e.size()){
            cout<<" "<<e[i];
        }cout<<endl;

        vint ans;
        if(o[0]>1)ans.pb(o[0]-1);
        rep(i,e.size())ans.pb(e[i]);
        ans.pb(1);

        cout<<ans.size()<<endl;
        rep(i,ans.size()){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }
    else{
        cout<<o[0]<<" ";
        rep(i,e.size())cout<<e[i]<<" ";
        cout<<o[1]<<endl;

        vint ans;
        if(o[0]>1)ans.pb(o[0]-1);
        rep(i,e.size())ans.pb(e[i]);
        ans.pb(o[1]+1);

        cout<<ans.size()<<endl;
        rep(i,ans.size()){
            if(i)cout<<" ";
            cout<<ans[i];
        }cout<<endl;
    }
    return 0;
}
