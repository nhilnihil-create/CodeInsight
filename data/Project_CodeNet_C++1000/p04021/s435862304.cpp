#include<bits/stdc++.h>
using Int = long long;
using namespace std;
int main(){
    Int N; cin >> N;
    vector<Int>v(N);
    for(auto& e : v)
        cin >> e;
    vector<Int>base = v;
    map<Int,Int>toIdx, dis;
    sort(base.begin(),base.end());
    for(Int id = 0; id  < N; ++id)
        toIdx[base[id]] = id;
    for(Int i = 0; i < N; ++i)
        dis[v[i]] = abs(i - toIdx[v[i]]);
    cout << accumulate(dis.begin(), dis.end(), 0LL,[](Int res, const pair<Int,Int> p){
        return res += ( p.second % 2);
    }) / 2<<endl;
}
