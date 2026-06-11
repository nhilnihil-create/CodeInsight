#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){

ll N, M, Ans = 0;cin >> N >> M;
vector<vector<ll>> V(N);

rep(i, 0, M){

    ll a, b;cin >> a >> b;

    V[a - 1].push_back(b - 1);

    V[b - 1].push_back(a - 1);
}

rep(i, 0, V[0].size()){
    
    rep(j, 0, V[V[0][i]].size()){

        if(V[V[0][i]][j] == N - 1){cout << "POSSIBLE";exit(0);}
    }

}

cout << "IMPOSSIBLE";

}