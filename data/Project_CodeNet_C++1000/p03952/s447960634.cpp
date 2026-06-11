#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
    ll n,x;cin>>n>>x;
    vector<ll> ans(2*n-1,0);

    if(x==1 || x==2*n -1){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;

    if(x>(2*n-1)/2){
        ans[(2*n-1)/2]=2*n-1;
        ans[(2*n-1)/2 -1]=1;
        ans[(2*n-1)/2 +1]=x;
        if((2*n-1)/2 +2 <2*n-1)ans[(2*n-1)/2 +2]=2;
        ll ind=0;
        for(int i=3;i < 2*n-1;i++)
        {
            if(ans[ind]==0){
                if(i!=x){
                    ans[ind]=i;
                    ind++;
                }
            }else{
                ind++;
                i--;
            }
        }
    }else{
        ans[(2*n-1)/2]=1;
        ans[(2*n-1)/2 -1]=2*n-1;
        ans[(2*n-1)/2 +1]=x;
        if((2*n-1)/2 +2 <2*n-1)ans[(2*n-1)/2 +2]=2*n-2;
        ll ind=0;
        for(int i=2;i < 2*n-2;i++)
        {
            if(ans[ind]==0){
                if(i!=x){
                    ans[ind]=i;
                    ind++;
                }
            }else{
                ind++;
                i--;
            }
        }
    }

    rep(i,2*n-1){
        cout<<ans[i]<< (i==2*n-2 ? '\n' : ' ');
    }
}

