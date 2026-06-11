#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution{

public:
    int mincost(const vector<int>& nums){

        int a = nums.size();
        int b = -2 * accumulate(nums.begin(), nums.end(), 0);
        int c = 0;
        for(int e: nums) c += e * e;

        if((-b) % (2 * a) == 0)return (4 * a * c - b * b) / (4 * a);

        int x1 = (-b) / (2 * a), x2 = x1 + 1;
        return min(a * x1 * x1 + b * x1 + c, a * x2 * x2 + b * x2 + c);
    }
};

int main() {

//    vector<int> nums1 = {4, 8};
//    cout << Solution().mincost(nums1) << endl;
//    // 8
//
//    vector<int> nums2 = {1, 1, 3};
//    cout << Solution().mincost(nums2) << endl;
//    // 3
//
//    vector<int> nums3 = {4, 2, 5};
//    cout << Solution().mincost(nums3) << endl;
//    // 5
//
//    vector<int> nums4 = {-100, -100, -100, -100};
//    cout << Solution().mincost(nums4) << endl;
//    // 0

    int N;
    scanf("%d", &N);

    vector<int> nums(N);
    for(int i = 0; i < N; i ++) scanf("%d", &nums[i]);
    printf("%d\n", Solution().mincost(nums));

    return 0;
}
