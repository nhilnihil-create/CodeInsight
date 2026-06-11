#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

int main() {
    int w, h; cin >> w >> h;
    vector<pair<int, int>> edge_w{};
    int wgt;
    for(int i=0; i<w; i++){
        cin >> wgt;
        edge_w.push_back(pair<int, int>{wgt, 0});
    }
    for(int i=0; i<h; i++){
        cin >> wgt;
        edge_w.push_back(pair<int, int>{wgt, 1});
    }
    sort(edge_w.begin(), edge_w.end(), 
         [](pair<int,int>& x, pair<int,int>& y){return x.first < y.first;});
    // for(auto& v:edge_w){
    //     cout << v.first << " " << v.second << endl;
    // }
    ll ans = 0;
    w++; h++;
    for(auto& v:edge_w){
        if(v.second == 0){
            ans += 1LL * h * v.first;
            w--;
        }
        else{
            ans += 1LL * w * v.first;
            h--;
        }
    }
    cout << ans << endl;
    return 0;
}