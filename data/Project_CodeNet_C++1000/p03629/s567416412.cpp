#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};


int main(){
    string A; cin>>A;
    ll N=A.size();
    vec d(N);
    vec D[26];
    rep(i,N) d.at(i)=A.at(i)-'a';
    vector<P> kireme;
    ll memory[26][2];
    rep(i,26) rep(j,2) memory[i][j]=-1;
    vec eachL[26], eachR[26];

    ll I=N-1, count=26, Kugiri=N;
    vector<bool> used(26,false);
    while(I>=0){
        ll k=d.at(I);
        if(used.at(k)) memory[k][0]=I;
        else{
            used.at(k)=true;
            memory[k][1]=I;
            memory[k][0]=I;
            count--;
            if(count==0){
                kireme.pb(mp(I,Kugiri));
                rep(j,26) eachL[j].pb(memory[j][0]);
                rep(j,26) eachR[j].pb(memory[j][1]);
                Kugiri=I;
                count=26;
                rep(j,26) used.at(j)=false;
            }
        }
        I--;
    }

    rep(i,26){
        reverse(ALL(eachL[i]));
        reverse(ALL(eachR[i]));
        reverse(ALL(kireme));
    }

    vec ans;
    rep(i,26) if(!used.at(i)){
        ans.pb(i);
        break;
    }

    rep(i,kireme.size()){
        int x=eachL[ans.at(i)].at(i);
        rep(j,26) if(eachR[j].at(i)<=x) {
            ans.pb(j);
            break;
        }
    }
    string ANS;

    rep(i,ans.size()) ANS.pb('a'+ans.at(i));
    cout<<ANS<<endl;






}

