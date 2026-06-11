#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>
#include <unordered_map>

using namespace std;

int main(){

    int H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> AB(N);
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        a--;
        b--;
        AB[i] = make_pair(a, b);
    }

    unordered_map<long long, int> cntMap;
    for(auto p: AB){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int x = p.first + i;
                int y = p.second + j;
                if(1 <= x && x < H - 1 && 1 <= y && y < W - 1){
                    cntMap[(long long)x * W + y]++;
                }
            }
        }
    }

    vector<long long> ans(10);
    for(auto temp: cntMap){
        ans[temp.second]++;
    }
    ans[0] = (long long)(H - 2) * (W - 2);
    for(int i = 1; i <= 9; i++){
        ans[0] -= ans[i];
    }

    for(auto temp: ans){
        cout << temp << endl;
    }

    return 0;
}