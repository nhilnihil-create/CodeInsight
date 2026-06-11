#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct cww{cww(){
    ios::sync_with_stdio(false);cin.tie(0);
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
template <typename T>inline void chmin(T &l,T r){l=min(l,r);}
template <typename T>inline void chmax(T &l,T r){l=max(l,r);}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}

const int MOD=1e9+7;
int main(){
    int N;
    cin>>N;
    vector<int> x(N),r(N),cnt(N,0);
    cin>>x;
    x[0]=1;
    FOR(i,1,N)chmin(x[i],x[i-1]+2);
    r[0]=0;
    cnt[0]=1;
    FOR(i,1,N){
        r[i]=i-(x[i-1]+1)/2;
        cnt[r[i]]++;
        DEBUG cout<<i<<x[i]<<r[i]<<" ";
    }DEBUG cout<<endl;
    LL res=1;
    LL now=0;
    REP(i,N){
        now+=cnt[i];
        
        DEBUG cout<<i<<" "<<now<<endl;
        res*=now;;
        res%=MOD;
        now--;
    }
    cout<<res<<endl;
    return 0;
}
