#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
using Pos = std::pair<int, int>;
//cout<<fixed<<std:cout<<fixed<<setprecision(2)<<Max<<endl;
constexpr int mod = 1e9 + 7;

vector<vector<int>> Edges;
vector<char> memo;

bool dfs(int node, int& size, char prev_color=0){
    ++size;
    if(prev_color==0){
        memo[node]=1;
    }else{
        memo[node]=prev_color*-1;
    }

    bool ans=false;
    for(const auto& val:Edges[node]){
        if(memo[val]==0){
            ans|=dfs(val,size,memo[node]);
        }else{
            if(memo[val]==memo[node])ans=true;
        }
    }

    return ans;
}

int main() {
    int N,M;
    cin>>N>>M;

    Edges.resize(N);
    memo.resize(N,0);
    for(int i = 0; i < M; ++i) {
        int a,b;
        cin>>a>>b;
        --a,--b;
        Edges[a].push_back(b);
        Edges[b].push_back(a);
    }


    long long iso_num=0;
    long long bi_num=0;
    long long not_bi_num=0;

    for(int i=0;i<N;++i){
        int size=0;
        if(memo[i]==0){
            bool is_bi=dfs(i,size);
            if(is_bi)++not_bi_num;
            else{
                if(size==1)++iso_num;
                else ++bi_num;
            }
        }
    }

    cout<<iso_num*(2*N-iso_num)+2*bi_num*bi_num+not_bi_num*not_bi_num+2*bi_num*not_bi_num<<endl;

    return 0;
}