#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int ans = 0;

    vector<int> vec(51);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end(), greater<int>()); // 降順（大きい順）でソー
    for (int i = 0; i < K; i++)
    {
        ans += vec[i];
    }

    cout << ans << endl;

    return 0;
}