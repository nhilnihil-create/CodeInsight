#include<iostream>
#include<vector>
using namespace std;
int main(){
    int W, H, N, A, B;
    cin >> W >> H >> N;
    int x_min = 0, x_max = W, y_min = 0, y_max = H;
    vector<int> x(N), y(N), a(N);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> a[i];
    }
    for(int i = 0; i < N; i++){
        if(a[i] == 1 && x_min < x[i]) x_min = x[i];
        if(a[i] == 2 && x_max > x[i]) x_max = x[i];
        if(a[i] == 3 && y_min < y[i]) y_min = y[i];
        if(a[i] == 4 && y_max > y[i]) y_max = y[i];
    }
    A = x_max - x_min;
    B = y_max - y_min;
    if(A < 0) A = 0;
    if(B < 0) B = 0;
    cout << A * B << endl;
}