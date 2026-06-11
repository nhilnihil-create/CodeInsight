//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = long long;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
const double PI=3.14159265358979323846;
const in MOD = 1000000007ll;
const in INF=1<<30;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};

//dijkstraの負も出来る版
//O(V*E)  V:頂点数,E:辺の数
//close=trueの時、負の閉路に到達
using T=tuple<in,in,in>;
const in MAX_dist=(in)(1e18);
vector<T> graph(0);//from,to,cost
vector<in> d(0);
in V,E;//V:頂点数,E:辺の数
bool close=false;
in ans1=MAX_dist,ans2=MAX_dist;

void init(in n){//辺をgraphに入れた後に
    d.resize(n,MAX_dist);
    V =n;
    // neg.resize(n,false);
}

void Bellman(in s,in n){//s:始点
    E=graph.size();
    d[s]=0;
    in close_cnt=0;
    close=false;
    while(1){//V回以上のループで負閉路に到達
        close_cnt ++;
        bool update=0;
        for(auto e: graph){
            in from,to,cost;
            tie(from,to,cost)=e;
            if(d[from]!=MAX_dist && d[to]>d[from]+cost){
                update =true;
                d[to]=d[from]+cost;
            }
        }
        if(!update) break;
        if(close_cnt==V+1ll) ans1=d[n-1];
        if(close_cnt==V*2+1ll){ans2=d[n-1];break;}
    }
}


int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10); 
    in n,m,a,b,c;
    cin>>n>>m;
    init(n);
    rep(i,m){
        cin>>a>>b>>c;
        c=-c;
        a --,b--;
        graph.emplace_back(a,b,c);
    }
    Bellman(0ll,n);
    in ans =d[n-1];
    ans *=(-1ll);
    if(ans1!=ans2 && ans2!=MAX_dist) cout<<"inf"<<endl;
    else cout<<ans<<endl;
}