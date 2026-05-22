class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long res = 0; // Use long to detect overflow
        int sign = 1;
        
        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') i++;
        
        // 2. Check sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Accumulate digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            
            // 4. Handle overflow immediately
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && -res < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return (int)(res * sign);
    }
};