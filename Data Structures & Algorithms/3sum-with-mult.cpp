class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long long> count;
        long long res = 0;
        int MOD = 1e9+7;
        for (int i: arr) count[i]++;
        for (int i = 0; i <= 100; ++i) {
            for (int j = i; j <= 100; ++j) {
                int third = target - i - j;
                
                // Enforce i <= j <= third to prevent duplicate permutations
                if (third < 0 || third > 100 || third < j) continue;
                
                if (i == j && j == third) {
                    // N choose 3
                    res += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
                }
                else if (i == j && j < third) {
                    // N choose 2
                    res += (count[i] * (count[i] - 1) / 2) * count[third];
                }
                else if (i < j && j == third) {
                    // N choose 2
                    res += count[i] * (count[j] * (count[j] - 1) / 2);
                }
                else {
                    // All distinct
                    res += count[i] * count[j] * count[third];
                }
                
                res %= MOD;
            }
        }
        return res;
    }
};

