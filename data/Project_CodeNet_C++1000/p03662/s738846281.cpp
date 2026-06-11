#define _USE_MATH_DEFINES
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

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const long long LINF = 1000000000000000000; // 1e18
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




int main(){
    int N; std::cin >> N;
    std::vector<std::vector<int>> G(N);
    std::vector<int> d0(N, -1), dN(N, -1);
    {
        int a, b;
        for(int i(0), i_len(N-1); i < i_len; ++i){
            std::cin >> a >> b;
            --a; --b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    d0[0] = 0;
    std::queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v(que.front()); que.pop();
        for(int e: G[v]){
            if(d0[e] != -1) continue;
            d0[e] = d0[v] + 1;
            que.push(e);
        }
    }
    dN[N-1] = 0;
    que.push(N-1);
    while(!que.empty()){
        int v(que.front()); que.pop();
        for(int e: G[v]){
            if(dN[e] != -1) continue;
            dN[e] = dN[v] + 1;
            que.push(e);
        }
    }
    int cnt(0);
    for(int i(0); i < N; ++i){
        if(d0[i] <= dN[i]) ++cnt; 
    }
    std::cout << ((2*cnt > N) ? "Fennec": "Snuke") << std::endl;
    return 0;
}
