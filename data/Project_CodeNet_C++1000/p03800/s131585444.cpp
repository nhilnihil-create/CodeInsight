#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> P;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

int main(){
    ll N; cin>>N;
    string S; cin>>S;
    vector<int> d(N,0);
    rep(i,N) if(S.at(i)=='o') d.at(i)=1;

    bool able=false;

    vector<int> ans(N);
    rep(k,4){
        bool okay=true;
        ans.at(0)=k/2;
        ans.at(1)=k%2;
        REP(i,1,N-1){
            ll x=(ans.at(i)+ans.at(i-1))%2;
            if(d.at(i)==1) ans.at(i+1)=1-x;
            else ans.at(i+1)=x;
        }
        if((ans.at(N-2)+ans.at(N-1)+ans.at(0))%2!=d.at(N-1)) okay=false;
        if((ans.at(N-1)+ans.at(0)+ans.at(1))%2!=d.at(0)) okay=false;
        if(okay) {able=true; break;}
    }
    if(able) rep(i,N){
        if(ans.at(i)) cout<<'S';
        else cout<<'W';
    }
    else cout<<-1;
    cout<<endl;

}