#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[]) {
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());

    if (nums[0] + nums[1] == nums[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
