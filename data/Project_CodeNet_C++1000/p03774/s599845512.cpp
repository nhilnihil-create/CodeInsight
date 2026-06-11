#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> zahyo(n);
    vector<pair<int,int>> checkpoint(m);
    vector<pair<int,int>> distance(m);
    for (int i = 0; i < n; i++){
        cin >> zahyo.at(i).first >> zahyo.at(i).second;
    }
    for (int i = 0; i < m; i++){
        cin >> checkpoint.at(i).first >> checkpoint.at(i).second;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            distance.at(j).first  = abs(zahyo.at(i).first - checkpoint.at(j).first)
                              + abs(zahyo.at(i).second - checkpoint.at(j).second);
            distance.at(j).second = j + 1;
        }
        sort(distance.begin(), distance.end());//小さい順に並べる
        cout << distance.at(0).second << endl;
    }
}