#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,M; cin>>N>>M;
    vector<vector<int>> city(N+1,vector<int>());

    while(M--){
        int a,b; cin>>a>>b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        cout << city[i].size() << endl;
    }
}
