#include<vector>
#include<tuple>
#include<limits>
class Bellman_Ford{
private:
    using size_type=std::vector<long long>::size_type;
public:
    using edge_vec=std::vector<std::tuple<size_type,size_type,long long>>;//edge={{from,to,cost}}
    static /*inline*/ constexpr auto inf=std::numeric_limits<long long>::max();
    static /*inline*/ constexpr auto minf=std::numeric_limits<long long>::min();
    static std::vector<long long>get_min_cost(const edge_vec&edge,size_type node_cnt,size_type start=0)
    {
        std::vector<long long>ret(node_cnt,inf);
        ret[start]=0;
        bool is_updated=false;
        for(size_type i=0;i<ret.size();++i){
            for(auto e:edge){
                size_type from=std::get<0>(e),to=std::get<1>(e);
                long long cost=std::get<2>(e);
                if(ret[from]!=inf&&ret[to]>ret[from]+cost){
                    ret[to]=ret[from]+cost;
                    is_updated=true;
                }
            }
            if(!is_updated)break;
        }
        if(is_updated){
            for(auto e:edge){
                size_type from=std::get<0>(e),to=std::get<1>(e);
                long long cost=std::get<2>(e);
                if(ret[from]==minf||ret[from]!=inf&&ret[to]>ret[from]+cost){
                    ret[to]=minf;
                }
            }
        }
        return ret;
    }
};

#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<typename T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<typename T=ll>inline auto vec2(typename vector<T>::size_type h,typename vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
int main()
{
    ll n=in(),m=in();
    Bellman_Ford::edge_vec e(m);
    for(ll i=0;i<m;++i){
        ll a=in(),b=in(),c=in();
        e[i]=make_tuple(a-1,b-1,-c);
    }
    auto dist=Bellman_Ford::get_min_cost(e,n);
    if(dist[n-1]!=Bellman_Ford::minf){
        cout<<-dist[n-1]<<endl;
    }else{
        cout<<"inf"<<endl;
    }
}
