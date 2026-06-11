#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> nums(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    int x = floor(sum / N);
    int y = ceil((float)sum / N);
    int ans1 = 0, ans2 = 0;
    for(auto index : nums) {
        ans1 += (index - x) * (index - x);
        ans2 += (index - y) * (index - y);
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}