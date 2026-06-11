#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll H,W;
    cin >> H >> W;
    char photo[2 * H][W];
    memset(photo, ' ', sizeof(photo));
    
    for(int i = 0; i < 2 * H; i += 2){
        for(int j = 0; j < W; j++){
            cin >> photo[i][j];
            photo[i + 1][j] = photo[i][j];
        }
    }

    for(int i = 0; i < 2 * H; i++){
        for(int j = 0; j < W; j++){
            cout << photo[i][j];
        }
        cout << endl;
    }
    cout << endl;

}
