#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    int *x = new int[N];
    int *y = new int[N];
    int *a = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> x[i] >> y[i] >> a[i];
    }
    int right = W;
    int left = 0;
    int top = H;
    int bottom = 0;
    for (int i = 0; i < N; ++i)
    {
        switch (a[i])
        {
        case 1:
            left = max(left, x[i]);
            break;
        case 2:
            right = min(right, x[i]);
            break;
        case 3:
            bottom = max(bottom, y[i]);
            break;
        case 4:
            top = min(top, y[i]);
            break;
        default:
            break;
        }
    }
    if (right - left > 0 && top - bottom > 0)
    {
        cout << (right - left) * (top - bottom) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}