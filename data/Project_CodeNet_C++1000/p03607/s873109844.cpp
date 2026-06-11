#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> A){
    map<long long, long long> paper;
    for(auto a : A){
        if(paper[a] == 0) paper[a] = 1;
        else paper[a] = 0;
    }
    long long ans = 0;
    for(auto itr = paper.begin(); itr != paper.end(); ++itr){
        if(itr->second == 1) ans++;
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
