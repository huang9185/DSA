class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(), 1);
        sort(words.begin(), words.end(), [](const string& a, const string& b){ return a.length() < b.length(); });
        int max_len = 1;
        for (int i = 1; i < words.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPre(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
    bool isPre(const string& a, const string& b) {
        if (a.length() + 1 != b.length()) return false;
        int i = 0, j = 0;
        bool inserted = false;
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) ++i;
            else {
                if (inserted) return false;
                inserted = true;
            }
            ++j;
        }
        return true;
    }
};