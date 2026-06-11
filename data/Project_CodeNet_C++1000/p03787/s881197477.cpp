#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

struct node{
    ll parent;
    ll black;
    ll white;
    ll dist;
    bool col;
};

vector<node> uft;

pll parent(ll a){
    if(uft[a].parent==a){return {a,0};}
    pll ret=parent(uft[a].parent);
    uft[a].dist+=ret.S;
    uft[a].parent=ret.F;
    ret.S=uft[a].dist;
    return {uft[a].parent,uft[a].dist};
}

void merge(ll a,ll b){
    pll A=parent(a),B=parent(b);
    if(A.F==B.F){
        if(((A.S+B.S)&1)==0){uft[A.F].col=false;}
    }
    else{
        if((A.S+B.S)&1){
            uft[A.F].white+=uft[B.F].white;
            uft[A.F].black+=uft[B.F].black;
            uft[A.F].col&=uft[B.F].col;
            uft[B.F].dist=0;
            uft[B.F].parent=A.F;
        }
        else{
            uft[A.F].white+=uft[B.F].black;
            uft[A.F].black+=uft[B.F].white;
            uft[A.F].col&=uft[B.F].col;
            uft[B.F].dist=1;
            uft[B.F].parent=A.F;
        }
    }
}


int main(){
    ll n,m;
    cin>>n>>m;
    uft.resize(n);
    for(int i=0;i<n;i++){
        uft[i].white=1;
        uft[i].black=0;
        uft[i].dist=0;
        uft[i].parent=i;
        uft[i].col=true;
    }
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        u--; v--;
        merge(u,v);
    }
    set<ll> S;
    ll one=0;
    ll dbl=0;
    ll tri=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        pll ret=parent(i);
        if(S.count(ret.F)==0){
            S.insert(ret.F);
            //cout<<ret.F<<" ";
            if(uft[ret.F].white+uft[ret.F].black==1){
                //cout<<"one"<<endl;
                ans+=n;
                one++;
            }
            else if(uft[ret.F].col){
                //cout<<"dbl"<<endl;
                dbl++;
            }
            else{
                //cout<<"tri"<<endl;
                tri++;
            }
        }
    }
    S.clear();
    //cout<<one<<" "<<dbl<<" "<<tri<<endl;
    for(int i=0;i<n;i++){
        pll ret=parent(i);
        if(S.count(ret.F)==0){
            S.insert(ret.F);
            if(uft[ret.F].white+uft[ret.F].black==1){
                ans+=(n-one);
            }
            else if(uft[ret.F].col){
                ans+=dbl*2;
                ans+=tri;
            }
            else{
                ans+=(dbl+tri);
            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
