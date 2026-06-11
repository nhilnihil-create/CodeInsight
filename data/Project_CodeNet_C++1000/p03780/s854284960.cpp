#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> GetSums(const vector<int> &nums, int k, int ignore)
{
    vector<bool> valid(k, false);
    for (size_t i = 0; i < nums.size(); i += 1) {
        if ((int)i == ignore) {
            continue;
        }
        for (int j = k - 1; j > nums[i]; j -= 1) {
            valid[j] = (valid[j] || valid[j - nums[i]]);
        }
        valid[nums[i]] = true;
    }
    return valid;
}

bool IsUseless(const vector<int> &nums, int k, int index)
{
    auto sums = GetSums(nums, k, index);
    auto num = nums[index];

    return !any_of(sums.begin() + k - num, sums.end(), [](bool b) { return b; });
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums;
    for (int i = 0; i < n; i += 1) {
        int num;
        cin >> num;

        if (num < k) {
            nums.push_back(num);
        }
    }

    sort(nums.begin(), nums.end());

    auto index = -1;
    auto power = (1 << 14);

    while (power > 0) {
        auto next_index = index + power;
        power >>= 1;

        if (next_index < (int)nums.size() && IsUseless(nums, k, next_index)) {
            index = next_index;
        }
    }

    auto res = index + 1;
    cout << res << "\n";

    return 0;
}
