#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
#define sign(a) ((a>0)-(a<0))
#define LL long long
#define INF (LL)(1LL<<60)


const long long MOD = 1000000007;

void solve(long long N, std::vector<std::string> S){
    LL i=0, ans=0;
    if(S[0][0]==S[1][0]){
        i=1;
        ans=3;
    }else{
        i=2;
        ans=6;
    }
    while(i<N){
        auto curr = S[0][i]==S[1][i];
        auto prev = S[0][i-1]==S[1][i-1];
        if(curr&&prev)ans=(2*ans)%MOD;
        if(!curr && prev)ans=(2*ans)%MOD;
        if(!curr && !prev)ans = (3*ans)%MOD;

        if(curr)i++;
        else i+=2;
    }

    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> S(2);
    for(int i = 0 ; i < 2 ; i++){
        std::cin >> S[i];
    }
    solve(N, std::move(S));
    return 0;
}
