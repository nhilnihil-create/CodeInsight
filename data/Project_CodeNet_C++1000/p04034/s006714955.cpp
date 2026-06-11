#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> x(100000, 0), y(100000, 0);
    vector<pair<int, bool>> memo;  // 玉の個数 赤があるか
    int ans = 0;
    for(int i=0; i<n; i++){
        if(i==0){
            memo.push_back(make_pair(1, true));
        }else{
            memo.push_back(make_pair(1, false));
        }
    }
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        x = x -1;
        y = y -1;
        if(memo[x].second){
            memo[y].second = true;
        }
        memo[x].first--;
        memo[y].first++;
        if(memo[x].first==0){
            memo[x].second = false;
        }
    }

    for(int i=0; i<n; i++){
        if(memo[i].second){
            ans ++ ;
        }
    }
    cout << ans << endl;
    return 0;    

}