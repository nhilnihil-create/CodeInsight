#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    i64 w, h;
    cin >> w >> h;
    vector<pair<i64,int>> v;
    for(int i=0;i<w;++i){
        i64 tmp;
        cin >> tmp;
        v.emplace_back(tmp, 0);
    }
    for(int i=0;i<h;++i){
        i64 tmp;
        cin >> tmp;
        v.emplace_back(tmp, 1);
    }

    sort(v.begin(), v.end());
    i64 ans = 0;
    for(auto e: v){
        if(e.second == 0){
            ans += e.first * (h+1);
            w--;
        }else{
            ans += e.first * (w+1);
            h--;
        }
    }

    cout << ans << endl;

    return 0;
}