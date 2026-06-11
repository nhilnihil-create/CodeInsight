#define _USE_MATH_DEFIMES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007;
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}


struct edge{
    int from, to, cost;
    edge(int From, int To, int Cost): from(From), to(To), cost(Cost){}
};

void bellmanFord_Cost(int V, std::vector<edge>& es, std::vector<long long>& d, int s){
    d.resize(V, LINF);
    d[s] = 0;
    while(1){
        bool update = false;
        for(auto &e : es){
            if(d[e.from] != LINF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }
}

bool find_negative_loop_Cost(int V, std::vector<edge>& es, std::vector<long long>& d, int s){
    d.resize(V, LINF);
    d[s] = 0;
    for(int i(0); i < V; ++i){
        for(auto &e : es){
            if(d[e.from] != LINF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                
                //V回目に更新なら負閉路あり
                if(i == V-1) return true;
            }
        }
    }
    return false;
}


int main(){
    int N, M; std::cin >> N >> M;
    std::vector<edge> es;
    {
        int a, b, c;
        for(int i(0); i < M; ++i){
            std::cin >> a >> b >> c;
            --a; --b;
            es.emplace_back(a, b, -c);
        }
    }
    std::vector<long long> d;
    find_negative_loop_Cost(N, es, d, 0);
    std::vector<bool> negativeloop(N, false);
    for(int i(0); i < N; ++i){
        for(auto &e : es){
            if(d[e.from] != LINF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                negativeloop[e.to] = true;
            }
            if(negativeloop[e.from]) negativeloop[e.to] = true;
        }
    }
    if(negativeloop[N-1]){
        std::cout << "inf" << std::endl;
    }else{
        std::cout << -d[N-1] << std::endl;
    }
    return 0;
}
