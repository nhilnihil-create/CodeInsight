#include <iostream>
#include <algorithm>

#define P 1000000007

using namespace std;

int main(){
    int n, m;
    long x[100000];
    long y[100000];
    cin >> n >> m;
    long x_sum = 0;
    long y_sum = 0;
    long x_diff = 0;
    long y_diff = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
    }
    sort(x, x+n);
    sort(y, y+m);
    x_sum = x[0];
    for(int i = 1; i < n;i++){
        x_diff = (x_diff + i*x[i] - x_sum)%P;
        x_sum = (x_sum + x[i])%P;
    }
    y_sum = y[0];
    for(int i = 1; i < m;i++){
        y_diff = (y_diff + i*y[i] - y_sum)%P;
        y_sum = (y_sum + y[i])%P;
    }
    cout << (x_diff*y_diff)%P << endl;
}