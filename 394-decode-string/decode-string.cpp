class Solution {
public:
    string decodeString(string s) {
        int ptr = 0;
        return recur(s, ptr);
    }
    string recur(const string& s, int& ptr) {
        string res = "";
        int num = 0;

        while (ptr != s.length()) {
            char c = s[ptr];
            ++ptr;
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                string cur = recur(s, ptr);
                while (num > 0) {
                    res += cur;
                    num--;
                }
            } else if (c == ']') return res;
            else res += c;
        }

        return res;
    }
};