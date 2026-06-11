#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define DIVCEIL(A,B) ((A+(B-1))/B)
#define LL long long
#define INF (LL)(1LL<<60)
using namespace std;


void solve(long long N, long long W, std::vector<long long> w, std::vector<long long> v){
    vector<vector<LL>> vs(4);
    vector<vector<LL>> accs(4);
    auto w1 = w[0];
    for(LL i=0; i<N; i++)vs[w[i]-w1].emplace_back(v[i]);
    for(LL i=0; i<4; i++)sort(vs[i].begin(), vs[i].end(), greater<LL>());
    for(LL i=0; i<4; i++){
        LL acc=0;
        accs[i].emplace_back(0);
        for(auto val: vs[i]){
            acc += val;
            accs[i].emplace_back(acc);
        }
    }
    LL ans=0;
    for(LL i=0; i<accs[0].size(); i++){
        for(LL j=0; j<accs[1].size(); j++){
            for(LL k=0; k<accs[2].size(); k++){
                for(LL l=0; l<accs[3].size(); l++){
                    if(w1*(i+j+k+l)+j+2*k+3*l > W)break;
                    ans = max(ans, accs[0][i]+accs[1][j]+accs[2][k]+accs[3][l]);
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long W;
    scanf("%lld",&W);
    std::vector<long long> w(N);
    std::vector<long long> v(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&w[i]);
        scanf("%lld",&v[i]);
    }
    solve(N, W, std::move(w), std::move(v));
    return 0;
}
