class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // start with first item in group 1, sum is nums[0]
        // dp[i][j] consider subset of first i nums with weight j
        // dp[i][j+1]?
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> memo(
            n, vector<int>(target+1, -1)
        );
        return helper(nums, 0, target, memo);
    }
    bool helper(const vector<int>& nums, int i, int target, 
        vector<vector<int>>& memo) {
            if (target < 0 || i >= nums.size()) return false;
            if (target == 0) return true;

            if (memo[i][target] != -1) return memo[i][target];
            bool include = helper(nums, i+1, target - nums[i], memo);
            bool exclude = helper(nums, i+1, target, memo);

            memo[i][target] = include || exclude;
            return memo[i][target];
        }
};

// time complexity: O(n*10K)
// space complexity: O(m)