#include <iostream>
using namespace std;
 
int main() {
    int W, H, N;
    int x[110];
    int y[110];
    int a[110];

    cin >> W >> H >> N; 
    int A[W][H];
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> a[i];
    }

    for(int j = 0; j < W; j++) {
        for(int k = 0; k < H; k++) {
            A[j][k] = 1;
        }
    }
    for(int i = 0; i < N; i++) {
        if(a[i] == 1) {
            for(int j = 0; j < x[i]; j++) {
                for(int k = 0; k < H; k++) {
                    A[j][k] = 0;
                }
            }
        }
        if(a[i] == 2) {
            for(int j = x[i]; j < W; j++) {
                for(int k = 0; k < H; k++) {
                    A[j][k] = 0;
                }
            }
        }
        if(a[i] == 3) {
            for(int j = 0; j < W; j++) {
                for(int k = 0; k < y[i]; k++) {
                    A[j][k] = 0;
                }
            }
        }
        if(a[i] == 4) {
            for(int j = 0; j < W; j++) {
                for(int k = y[i]; k < H; k++) {
                    A[j][k] = 0;
                }
            }
        }
    }

    int count = 0;
    for(int j = 0; j < W; j++) {
        for(int k = 0; k < H; k++) {
            if(A[j][k] == 1) {
                count++;
            }
        }
    }
    cout << count << endl;

}