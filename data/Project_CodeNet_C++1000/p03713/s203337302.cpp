#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

using ull = unsigned long long;

int main()
{
    ull H, W;
    cin >> H >> W;

    ull ans = ULONG_LONG_MAX;
    vector<ull> areas(3);
    // full width
    for (ull h = 1; h <= H - 1; h++) {
        ull max_a, min_a;
        areas[0] = h * W;

        areas[1] = ((H - h) / 2) * W;
        areas[2] = ((H - h) - ((H - h) / 2)) * W;

        max_a = *max_element(areas.begin(), areas.end());
        min_a = *min_element(areas.begin(), areas.end());
        ans = min(ans, max_a - min_a);

        areas[1] = (H - h) * (W / 2);
        areas[2] = (H - h) * (W - (W / 2));

        max_a = *max_element(areas.begin(), areas.end());
        min_a = *min_element(areas.begin(), areas.end());
        ans = min(ans, max_a - min_a);
    }

    // full height
    for (ull w = 1; w <= W - 1; w++) {
        ull max_a, min_a;
        areas[0] = w * H;

        areas[1] = H * ((W - w) / 2);
        areas[2] = H * (W - w - ((W - w) / 2));

        max_a = *max_element(areas.begin(), areas.end());
        min_a = *min_element(areas.begin(), areas.end());
        ans = min(ans, max_a - min_a);

        areas[1] = (H / 2) * (W - w);
        areas[2] = (H - (H / 2)) * (W - w);

        max_a = *max_element(areas.begin(), areas.end());
        min_a = *min_element(areas.begin(), areas.end());
        ans = min(ans, max_a - min_a);
    }

    cout << ans << endl;
}
