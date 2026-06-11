#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> x(N), y(N), a(N);

    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> a[i];
    }

    pair<int, int> rangeX = {0, W};
    pair<int, int> rangeY = {0, H};

    for(int i = 0; i < N; i++){
        switch (a[i])
        {
        case 1:
            if(rangeX.first < x[i]){
                rangeX.first = x[i];
            }
            break;
        case 2:
            if(rangeX.second > x[i]){
                rangeX.second = x[i];
            }
            break;
        case 3:
            if(rangeY.first < y[i]){
                rangeY.first = y[i];
            }
            break;
        case 4:
            if(rangeY.second > y[i]){
                rangeY.second = y[i];
            }
            break;
        }

    }

    int w = max(rangeX.second - rangeX.first, 0);
    int h = max(rangeY.second - rangeY.first, 0);

    cout << w * h << endl;

    return 0;
}
