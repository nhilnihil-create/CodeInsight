#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long ;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int N, int M, vector<P> const &ab, vector<P> const &cd, vector<int> &ans){

    ll dx{}, dy{}, dist = INF, dist_buf = INF;
    int pos{};
    for(int i = 0; i != N; ++i){
        for(int j = 0; j != M; ++j){
            dx = abs(ab.at(i).first - cd.at(j).first);
            dy = abs(ab.at(i).second - cd.at(j).second);
            dist_buf = dx + dy;
            
            if(dist > dist_buf){
                dist = dist_buf;
                pos = j+1;
            }
            dist_buf = INF; 
        }
        ans.at(i) = pos;
        dist = INF;
        pos = 0;
    }

    return;
}

int main(){

    int N, M;
    cin >> N >> M;
    vector<P> ab(N);
    vector<P> cd(M);
    for(auto iter = ab.begin(); iter != ab.end(); ++iter) cin >> (*iter).first >> (*iter).second;
    for(auto iter = cd.begin(); iter != cd.end(); ++iter) cin >> (*iter).first >> (*iter).second;

    vector<int> ans(N);
    solver(N, M, ab, cd, ans);

    for(auto iter = ans.begin(); iter != ans.end(); ++iter) cout << *iter << endl;

    return 0;
}