#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9+7;

vector<pair<int,int>> prime_factorize(int N){

    vector<pair<int,int>> num;
    
    for(int i=2; i<=N; i++){
        if(N%i != 0) continue;
        int e = 0;
        while(N%i==0){
            e++;
            N /= i;
        }
        num.push_back({i,e});
    }

    if(N != 1) num.push_back({N,1});

    return num;
}

int main(){
    int N;
    cin>>N;
    vector<int> cnt(N+1,0);

    for(int i=2; i<=N; i++){
        auto tmp = prime_factorize(i);
        for(auto a : tmp){
            cnt[a.first] += a.second;
        }
    }

    long long ans = 1;

    for(int i=2; i<=N; i++){
        ans *= cnt[i]+1;
        ans %= MOD;
    }

    cout<<ans<<endl;

    return 0;
}