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

int N,M;
int a[305][305];
int b[305][305];

signed main(){
    cin>>N>>M;
    set<int> st;
    rep(i,N){
        rep(j,M){
            cin>>a[i][j];
            a[i][j]--;
            st.insert(j);
        }
    }
    int ans=301;
    while(!st.empty()){
        map<int,int> mp;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(st.count(a[i][j])){
                    mp[a[i][j]]++;
                    break;
                }
            }
        }
        int cnt=0;
        for(auto pp:mp){
            chmax(cnt,pp.sc);
        }
        chmin(ans,cnt);
        set<int> ss;
        for(auto pp:mp){
            if(cnt==pp.sc){
                ss.insert(pp.ft);
            }
        }
        for(int s:ss) st.erase(s);
    }
    cout<<ans<<endl;
}