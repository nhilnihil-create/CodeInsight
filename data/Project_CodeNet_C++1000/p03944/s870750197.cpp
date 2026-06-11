#include <bits/stdc++.h>
using namespace std;

int main(void){
    int W,H,N;
    cin >> W >> H >> N;
    int x[N],y[N],a[N];
    for(int i = 0 ; i < N ; i++){
        cin >> x[i] >> y[i] >> a[i];
    }
    
    bool judge[H][W];
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            judge[i][j] = true;
        }
    }
    
    for(int k = 0 ; k < N ; k++){
        if(a[k] == 1){
            for(int i = 0 ; i < H ; i++){
                for(int j = 0 ; j < x[k] ; j++){
                    judge[i][j] = false;
                }
            }
        }else if(a[k] == 2){
            for(int i = 0 ; i < H ; i++){
                for(int j = x[k] ; j < W ; j++){
                    judge[i][j] = false;
                }
            }
        }else if(a[k] == 3){
            for(int i = 0 ; i < y[k] ; i++){
                for(int j = 0 ; j < W ; j++){
                    judge[i][j] = false;
                }
            }
        }else if(a[k] == 4){
            for(int i = y[k] ; i < H ; i++){
                for(int j = 0 ; j < W ; j++){
                    judge[i][j] = false;
                }
            }
        }
    }
    
    int counter = 0;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            if(judge[i][j] == true){
                counter++;
            }
        }
    }
    cout << counter << endl;
    return 0;
}