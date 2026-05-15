class Solution {
public:
    string minWindow(string s, string t) {
        int need = 0, have = 0;
        unordered_map<char, int> fre;
        for (auto c : t) {
            if (!fre.count(c)) need++;
            fre[c]++;
        }
        int left = 0, right = 0;
        int min_left = 0, size = INT_MAX;
        while (right != s.length()) {
            // if cur is needed, decrease fre counter
            // if no more such char is need, have ++
            if (fre.count(s[right])) {
                fre[s[right]]--;
                if (fre[s[right]] == 0) have++;
            }
            while (have == need) {
                char c = s[left];
                if (right - left + 1 < size) {
                    min_left = left;
                    size = right-left+1;
                }
                left++;
                // if this char is needed, have--
                // else if have == need we find a shorter string
                if (fre.count(c)) {
                    fre[c]++;
                    if (fre[c]>0) have--;
                }
            }
            right++;
        }
        return size == INT_MAX ? "" : s.substr(min_left, size);
    }
};

