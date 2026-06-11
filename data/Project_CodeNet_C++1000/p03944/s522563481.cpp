#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int xy[110][110];
int main() {
    int W, H, N;
    cin >> W >> H >> N;
    int x[110], y[110];
    int a[110];
    int s = 0;
    for(int i = 0; i < N; i++)
        cin >> x[i] >> y[i] >> a[i];

    for(int i = 0; i < N; i++){
        switch (a[i]){
            case 1:{
                for(int j = 0; j < x[i]; j++){
                    for(int k = 0; k < H; k++){
                        xy[j][k] = 1;
                    }
                }
                break;
            }
            case 2:{
                 for(int j = x[i]; j < W; j++){
                    for(int k = 0; k < H; k++){
                        xy[j][k] = 1;
                    }
                }
                break;
            }
            case 3:{
                 for(int j = 0; j < W; j++){
                    for(int k = 0; k < y[i]; k++){
                       xy[j][k] = 1;
                    }
                }
                break;
            } 
            case 4:{
                for(int j = 0; j < W; j++){
                    for(int k = y[i]; k < H; k++){
                       xy[j][k] = 1;
                    }
                }
                break;
            }
        }
    }
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(xy[i][j] == 0) s++;
        }
    }
    cout << s << endl;
    return 0;
}