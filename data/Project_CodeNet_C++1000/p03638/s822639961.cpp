#include <bits/stdc++.h>
using namespace std;

#define lint long long


int main(){
    int H, W, N; cin >> H >> W >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    vector<vector<int>> ans(H);
    
    int X = 0, Y = 0;
    
    for(int i = 0; i < N; ++i){
        while(true){
            int b = W - X;
            if(b >= a[i]){
                for(int j = 0; j < a[i]; ++j){
                    ans[Y].push_back(i + 1);
                }
                X += a[i];
                break;
            } else {
                for(int j = 0; j < b; ++j){
                    ans[Y].push_back(i + 1);
                }
                a[i] -= b;
                X = 0; Y++;
            }
        }
        
    }
    
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(i % 2 == 0){
                cout << ans[i][j] << " ";
            } else {
                cout << ans[i][W - 1 - j] << " ";
            }
        }
        cout << endl;
    }
    
}
