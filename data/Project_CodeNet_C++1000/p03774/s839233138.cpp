#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N,M;
    cin >> N >> M;
    vector<long long> a(N);
    vector<long long> b(N);
    vector<long long> c(M);
    vector<long long> d(M);
    
    rep(i,N)cin >>a[i] >> b[i];

    rep(i,M)cin >>c[i] >> d[i];

    typedef pair<long long, int> ManDist;
    auto comp = [](ManDist l, ManDist r){
        if(l.first != r.first){
            return (l.first > r.first);
        }else{
            return (l.second > r.second);
        }
    };
    // auto comp = [](ManDist l, ManDist r){return (l.first > r.first); };

    rep(i,N){
        priority_queue<ManDist, vector<ManDist>, decltype(comp)> que(comp);
        for(int j=0; j<M; j++){
            long long dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            // cout << dist << " : " << j << endl;
            que.push(ManDist(dist, j+1));
        }
        ManDist man = que.top();
        cout << man.second << endl;
    }
    return 0;
}