#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define fin "\n"


#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)

template <typename T>
inline void chmin(T &l,T r){l=min(l,r);}

template <typename T>
inline void chmax(T &l,T r){l=max(l,r);}

typedef vector<int> V;

int main(){
    int N,M;
    map<int,int > X;
    cin>>N>>M;
    REP(i,N){
        int x;cin>>x;X[x]++;
    }
    V mod_single(M,0);
    V mod_double(M,0);
     for(auto &it:X){
        int key=it.first%M;
        mod_double[key]+=it.second/2;
        mod_single[key]+=it.second%2;
    }
    LL res=0;
    REP(i,M){
        int j=(M-i)%M;
        if(i==j){
            res+=mod_single[i]/2;
            mod_single[i]%=2;
        }
        else{
        int y=min(mod_single[i],mod_single[j]);
        res+=y;
        mod_single[i]-=y;
        mod_single[j]-=y;
        }
        //cout<<i<<" "<<j<<" "<<y<<endl;
    }
    REP(i,M){
        mod_single[i]/=2;
    }
    REP(i,M){
        int j=(M-i)%M;
        int y=min(mod_single[i],mod_double[j]);
        res+=2*y;
        mod_single[i]-=y;
        mod_double[j]-=y;
        //cout<<i<<" "<<i<<" "<<2*y<<endl;

    }
    REP(i,M){
        res+=mod_double[i];
    }
    cout<<res<<endl;

    return 0;
}
