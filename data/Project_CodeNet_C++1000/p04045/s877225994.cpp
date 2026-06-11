#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> D(K);
    for(int i = 0; i < K; i++) cin >> D[i];
    vector<int> use;
    for(int i = 0 ; i < 10; i++){
        int flag = 0;
        for(int j = 0; j < K; j++){
            if(i == D[j]) flag = 1;
        }
        if(flag == 0) use.push_back(i);
    }
    queue<int> q;
    for(int i = 0; i < use.size(); i++){
        if(use[i] != 0) q.push(use[i]);
    }
    int ans = 0;
    while(!q.empty()){
        int t = q.front();
        if(t >= N){
            ans = t;
            break;
        }
        q.pop();
        for(int i = 0; i < use.size(); i++){
            q.push(t*10 + use[i]);
        }
    }
    cout << ans << endl;
}