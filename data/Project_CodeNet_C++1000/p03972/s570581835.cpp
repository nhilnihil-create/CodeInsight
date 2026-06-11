#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
#define int ll

signed main(){
    int H,W;
    cin >> W >> H;
    vector<int>p(W),q(H);
    for(auto & e : p) cin >> e;
    for(auto & e : q) cin >> e;
    using pi = pair<int,int>;
    vector<pi>v;
    for(auto e : p)
        v.push_back({e,1});
    for(auto e : q)
        v.push_back({e,0});
    sort(v.begin(),v.end());
    int pc = 0,qc = 0;
    int sum = 0;
    for(auto e : v){
        int cost = e.first, isP = e.second;
        if(isP){
            int cnt = H - qc + 1;
            sum += cnt * cost;
            ++pc;
        } else {
            int cnt = W - pc + 1;
            sum += cnt * cost;
            ++qc;
        }
    }
    cout << sum << endl;
}
