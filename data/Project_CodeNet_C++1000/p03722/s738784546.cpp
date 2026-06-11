#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
//#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false

class BellmanFord{
    /*
    Copyright (c) 2020 0214sh7
    https://github.com/0214sh7/library/
    */
    private:
    typedef std::pair<std::pair<int,int>,long long> P;
    int V,E;
    long long INF = (1LL<<61);
    std::vector<std::pair<std::pair<int,int>,long long>> es;
    
    public:
    void init(std::vector<std::pair<std::pair<int,int>,long long>> edge){
        //辺数をもとめる　
        E=edge.size();
        //頂点数を決定する
        V=0;
        for(int i=0;i<edge.size();i++){
            V=std::max(V,edge[i].first.first+1);
            V=std::max(V,edge[i].first.second+1);
        }
        es=edge;
    }
    
    std::vector<std::pair<long long,bool>> solve(int s){
        std::vector<std::pair<long long,bool>> d;
        //INFで初期化する
        for(int i=0;i<V;i++){
            d.push_back({INF,false});
        }
        d[s].first=0;
        for(int j=0;j<2*V;j++){
             bool update=false;
            for(int i=0;i<E;i++){
                P k=es[i];
                if(d[k.first.first].first!=INF && d[k.first.second].first>d[k.first.first].first+k.second){
                    d[k.first.second].first=d[k.first.first].first+k.second;
                    if(j>=V){
                        d[k.first.second].second=true;
                    }
                    update=true;
                }
            }
            if(!update)break;
        }
        return d;
    }
    
    //init:{ {int,int},longlong}のvectorを渡すことで有向グラフを構築する
    //solve:始点を渡すとinitで構築したグラフでベルマンフォードをし、コストのvectorを返す
};


signed main(void){
    int N,M;
    int a,b,c;
    vector<std::pair<std::pair<int,int>,long long>> es;
    cin >> N >> M;
    REP(i,M){
        cin >> a >> b >> c;
        a--;b--;c*=-1;
        es.push_back({{a,b},c});
    }
    
    BellmanFord bell;
    bell.init(es);
    
    std::vector<std::pair<long long,bool>> S;
    S = bell.solve(0);
    
    if(S[N-1].second){
        cout << "inf" << endl;
    }else{
        cout << -1*S[N-1].first << endl;
    }
    
    return 0;
}

