#include <bits/stdc++.h>
using namespace std;
int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    vector<vector<int>> b(H, vector<int>(W));
    for (int i = 0; i < N; i++){
        cin >> a.at(i);
    }
    queue<int> q;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < a.at(i); j++){
            q.push(i + 1);
        }
    }
    int w = 0, h = 0;
    for (int i = 0; i < H * W; i++){
        int k = q.front();
        q.pop();
        b.at(h).at(w) = k;
        if (h % 2 == 0){
            if (w < W - 1){
                w++;
                continue;
            }
            else{
                h++;
            }
        }
        else {
            if (w > 0){
                w--;
                continue;
            }
            else{
                h++;
            }
        }
    }
    for (int y = 0; y < H; y++){
        for (int x = 0; x < W; x++){
            cout << b.at(y).at(x);
            if (x != W - 1) cout << " ";
        }
        cout << endl;
    }
}
