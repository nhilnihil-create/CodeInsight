#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(long long N, long long M, std::vector<std::vector<long long>> A){
    vector<queue<int>> sport(N);
    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++)
            sport[i].push(A[i][j]);
    
    auto check = [&](int k){
        vector<queue<int>> q = sport;
        set<int> ng;
        while(1){
            map<int, int> mp;
            for(int i = 0;i < N;i++){
                while(ng.find(q[i].front()) != ng.end()){
                    q[i].pop();
                    if(q[i].empty())return false;
                }
                mp[q[i].front()]++;
            }
            bool f = false;
            for(auto a : mp){
                if(a.second > k){
                    f = true;
                    ng.insert(a.first);
                }
            }
            if(!f){
                return true;
            }
        }
    };
    ll ok = 1e9;
    ll ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<std::vector<long long>> A(N, std::vector<long long>(M));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    solve(N, M, std::move(A));
    return 0;
}
