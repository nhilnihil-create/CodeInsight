#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){

    int N;
    cin >> N;

    vector<vector<int>> battle_graph(N);
    rep(i, N - 1){
        int a;
        cin >> a;
        a--;
        battle_graph[a].push_back(i + 1);
    }

    function<int(int)> decide_battle = [&](int contestant){
        vector<int> battles;
        for(int oponent : battle_graph[contestant]){
            battles.push_back(decide_battle(oponent));
        }
        sort(all(battles), greater<int>());
        int max_battles = 0;
        rep(i, (int)battles.size()){
            chmax(max_battles, battles[i] + i + 1);
        }
        return max_battles;
    };

    cout << decide_battle(0) << endl;
    return 0;

}