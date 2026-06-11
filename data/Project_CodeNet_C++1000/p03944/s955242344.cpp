#include <iostream>
#include <vector>
using namespace std;

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n), a(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> a[i];

    vector<vector<bool>> memo(h, vector<bool>(w, false));

    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            for(int j = 0; j < h; j++){
                for(int k = 0; k < x[i]; k++){
                    memo[j][k] = true;
                }
            }
        }else if(a[i] == 2){
            for(int j = 0; j < h; j++){
                for(int k = x[i]; k < w; k++){
                    memo[j][k] = true;
                }
            }
        }else if(a[i] == 3){
            for(int j = 0; j < y[i]; j++){
                for(int k = 0; k < w; k++){
                    memo[j][k] = true;
                }
            }
        }else{
            for(int j = y[i]; j < h; j++){
                for(int k = 0; k < w; k++){
                    memo[j][k] = true;
                }
            }
        }
    }

    int ans = 0;
    for(int i = h-1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            if(!memo[i][j]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}