#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,x;cin>>n>>x;
    vector<ll>ans(2*n);
    if(x==1||x==2*n-1){
        cout<<"No"<<endl;
    }else{
        set<ll>st;
        ans[n]=x;
        ans[n-1]=x-1;
        ans[n+1]=x+1;
        st.insert(x);
        st.insert(x+1);
        st.insert(x-1);
        ll l=1;
        REP(i,1,2*n){
            if(ans[i])continue;
            while(st.find(l)!=st.end()){
                l++;
            }
            ans[i]=l;
            st.insert(l);
        }
        cout<<"Yes"<<endl;
        REP(i,1,2*n){
            cout<<ans[i]<<endl;
        }
    }
}