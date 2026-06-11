#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可
//乗算の際にオーバーフローに注意せよ！！（適切にmodをとれ）
//制約をよく読め！

const ll INF=1e18;

signed main(){
    int n;
    cin>>n;
    map<int,int> mp;
    V<int> a(n);
    rep(i,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(all(a));
    int m=a[n-1]+1;
    bool ok=1;
    if(a[0]<m/2) ok=0;
    if(ok){
        if(m%2==0){
            if(a[0]!=m/2) ok=0;
            if(a[0]==m/2&&mp[a[0]]!=2) ok=0;
        }else{
            if(a[0]!=m/2) ok=0;
            if(a[0]==m/2&&mp[a[0]]!=1) ok=0;
        }
        set<int> st;
        for(auto pp:mp){
            int u=pp.ft,v=pp.sc;
            st.insert(u);
            if(u!=m/2){
                if(v<2) ok=0;
            }
        }
        int t=st.size();
        if(m%2==0){
            if(t<m/2) ok=0;
        }else{
            if(t<m/2+1) ok=0;
        }
    }
    if(ok) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}