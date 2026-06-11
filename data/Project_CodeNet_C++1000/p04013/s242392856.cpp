#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


class Solution{

public:
    long long ways(vector<int>& nums, int A){

        int n = nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n + 1, vector<long long>(n * A + 1, -1)));

        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = 1; i <= n; i ++)
            res += solve(nums, 0, i, i * A, dp);
        return res;
    }

private:
    long long solve(const vector<int>& nums, int index, int left, int N,
                    vector<vector<vector<long long>>>& dp){

        if(index == nums.size())
            return N == 0 && left == 0 ? 1 : 0;
        if(left == 0) return N == 0 ? 1 : 0;
        if(dp[index][left][N] != -1) return dp[index][left][N];

        if(nums[index] > N) return 0;

        long long res = solve(nums, index + 1, left, N, dp);
        if(nums[index] <= N && left) res += solve(nums, index + 1, left - 1, N - nums[index], dp);
        return dp[index][left][N] = res;
    }
};

int main() {

//    vector<int> nums1 = {7, 9, 8, 9};
//    cout << Solution().ways(nums1, 8) << endl;
//    // 5
//
//    vector<int> nums2 = {6, 6, 9};
//    cout << Solution().ways(nums2, 8) << endl;
//    // 0
//
//    vector<int> nums3 = {3, 6, 2, 8, 7, 6, 5, 9};
//    cout << Solution().ways(nums3, 5) << endl;
//    // 19
//
//    vector<int> nums4(33, 3);
//    cout << Solution().ways(nums4, 3) << endl;
//    // 8589934591

    int N, A;
    scanf("%d%d", &N, &A);

    vector<int> nums(N);
    for(int i = 0; i < N; i ++) scanf("%d", &nums[i]);
    printf("%lld\n", Solution().ways(nums, A));

    return 0;
}
