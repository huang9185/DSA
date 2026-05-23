class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] to be the largest length of the increasing subseq ending at index i
        int n = nums.size();
        vector<int> lengths(n, 1);
        int maxLen = 1;
        for (int i = 1 ; i < n ; ++i) {
            for (int j = 0; j < i; ++j) {
                lengths[i] = max(lengths[i], nums[j] < nums[i]? lengths[j] + 1: 0);
            }
            maxLen = max(maxLen, lengths[i]);
        }
        return maxLen;
    }
};