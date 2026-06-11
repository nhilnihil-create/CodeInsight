#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
long long p[100000];
long long q[100000];
int main(void){
    // Your code here!
    int W;
    int H;
    cin >> W >> H;
    for(int i = 0; i < W; i++){
        cin >> p[i];
    }
    for(int i = 0; i < H; i++){
        cin >> q[i];
    }
    
    vector <pair <long long, bool> > pq;
    for(int i = 0; i < W; i++){
        pq.push_back(make_pair(p[i], true));
    }
    for(int i = 0; i < H; i++){
        pq.push_back(make_pair(q[i], false));
    }
    
    sort(pq.begin(), pq.end());
    long long total_cost = 0;
    int vertical_set_num = W + 1;
    int horizontal_set_num = H + 1;
    for(int i = 0; i < pq.size(); i++){
        long long cur_cost = pq[i].first;
        bool is_p = pq[i].second;
        if(is_p){
            total_cost += horizontal_set_num * cur_cost;
            vertical_set_num --;
        } else {
            total_cost += vertical_set_num * cur_cost;
            horizontal_set_num --;
        }
    }
    cout << total_cost << endl;
}