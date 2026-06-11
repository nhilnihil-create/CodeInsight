#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> roads;
vector<int> distances;

void snuke_move(int now, int back, int distance_all){
    distances[now] = distance_all;
    for(int i = 0; i < roads[now].size(); i++){
        if(roads[now][i] != back){
            snuke_move(roads[now][i], now, distance_all + 1);
        }
    }
}

int fennec_move(int now, int back){
    int ans = 1;
    for(int i = 0; i < roads[now].size(); i++){
        if(roads[now][i] != back && distances[roads[now][i]] * 2 >= distances[0]){
            ans += fennec_move(roads[now][i], now);
        }
    }
    return ans;
}

int main(){
    int N;
    cin >> N;
    roads.resize(N);
    for(int i = 0; i < N - 1; i++){
        int start, goal;
        cin >> start >> goal;
        roads[start - 1].push_back(goal - 1);
        roads[goal - 1].push_back(start - 1);
    }
    distances.resize(N);
    snuke_move(N - 1, -1, 0);
    if(fennec_move(0, -1) * 2 > N){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
}
