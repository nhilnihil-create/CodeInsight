#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i,s,n) for(ll i=(s);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,m;cin>>n>>m;
    vector<tuple<int,int,int>> edge(m);
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;
        edge[i]=make_tuple(a,b,c);
    }
    vll d(n+1,-INF);
    d[1]=0;
    bool update;
    int res=0;
    int tmp;
    while(1){
        res++;
        update=false;
        for(auto e:edge){
            if(d[get<0>(e)]!=-INF&&d[get<1>(e)]<d[get<0>(e)]+(ll)get<2>(e)){
                d[get<1>(e)]=d[get<0>(e)]+(ll)get<2>(e);
                update=true;
            }
        }
        if(!update)break;
        //正のループがあったとしてもそれによってd[n]が大きくできるとは限らないため2n回(ループのノード数は最大でもn)やってd[n]が更新されるか調べる。
        if(res==n-1)tmp=d[n];
        if(res==2*n&&tmp!=d[n]){
            cout<<"inf"<<endl;
            return 0;
        }
        if(res==2*n&&tmp==d[n])break;
    }
    cout<<d[n]<<endl;
}